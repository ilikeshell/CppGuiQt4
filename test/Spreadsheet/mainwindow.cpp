#include <QtWidgets>
#include <QStringList>
#include <QSettings>

#include "mainwindow.h"
#include "finddialog.h"
#include "gotocelldialog.h"
#include "sortdialog.h"
#include "spreadsheet.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    spreadsheet = new Spreadsheet;
    setCentralWidget(spreadsheet);

    createActions();
    createMenus();
    createContextMenu();
    createToolbars();
    createStatusBar();

    readSettings();

    findDialog = nullptr;

    setWindowIcon(QIcon(":/images/icon.png"));

    setCurrentFile("");
}

MainWindow::~MainWindow()
{
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(okToContinu()){
        writeSetting();
        event->accept();
    }else
        event->ignore();
}

void MainWindow::newFile()
{
    if(okToContinu()){
        spreadsheet->clear();
        setCurrentFile("");
    }
}

void MainWindow::open()
{
    if(okToContinu()){
        QString fileName = QFileDialog::getOpenFileName(this,
                    tr("Open Spreadsheet"), ".", tr("Spreadsheet files （*.sp）"));
        if(!fileName.isEmpty())
            loadFile(fileName);
    }
}

bool MainWindow::save()
{
    if(curFile.isEmpty())
        return saveAs();
    else
        return saveFile(curFile);
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Spreadsheet"), ".",
                                                    tr("Spreadsheet files (*.sp)"));
    if(fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

void MainWindow::find()
{
    if(!findDialog){
        findDialog = new FindDialog(this);
        connect(findDialog, SIGNAL(findNext(const QString&,Qt::CaseSensitivity)),
                spreadsheet, SLOT(findNext(const QString&, Qt::CaseSensitivity)));

        connect(findDialog, SIGNAL(findPrevious(const QString&,Qt::CaseSensitivity)),
                spreadsheet, SLOT(findPrevious(const QString&, Qt::CaseSensitivity)));
    }
    findDialog->show();
    findDialog->raise();
    findDialog->activateWindow();
}

void MainWindow::goToCell()
{
    GoToCellDialog *dialog = new GoToCellDialog(this);
    if(dialog->exec()){
        QString str = dialog->lineEdit->text().toUpper();
        spreadsheet->setCurrentCell(str.mid(1).toInt() - 1,
                                   str[0].unicode() - 'A');
    }
    delete dialog;
}

void MainWindow::sort()
{
    SortDialog dialog(this);
    QTableWidgetSelectionRange range = spreadsheet->selectedRange();
    dialog.setColumnRange('A' + range.leftColumn(),
                          'A' + range.rightColumn());

    if(dialog.exec()){
        SpreadsheetCompare compare;
        compare.keys[0] = dialog.primaryColumnComBo->currentIndex();
        compare.keys[1] = dialog.secondaryColumnComBo->currentIndex() - 1;
        compare.keys[2] = dialog.tertiaryColumnComBo->currentIndex() - 1;
        compare.ascending[0] = (dialog.primaryOrderComBo->currentIndex() == 0);
        compare.ascending[1] = (dialog.secondaryOrderComBo->currentIndex() == 0);
        compare.ascending[2] = (dialog.tertiaryOrderComBo->currentIndex() == 0);
        spreadsheet->sort(compare);
    }
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Spreadsheet"), tr("<h2>Spreadsheet 1.1<h2>"
                                                         "<p>Copyright &copy; 2023 Software Inc"));

}

void MainWindow::openRecentFile()
{
    if(okToContinu()){
        QAction *action = qobject_cast<QAction *>(sender());
        if(action)
            loadFile(action->data().toString());
    }
}

/*
void MainWindow::updateStatusBar()
{
    locationLabel->setText(spreadsheet->currentLocation());
    formulaLabel->setText(spreadsheet->currentFormula());
}


void MainWindow::spreadsheetModified()
{
    setWindowModified(true);
    updateStatusBar();
}
*/

void MainWindow::createActions()
{
    newAction = new QAction(tr("&New"), this);
    newAction->setIcon(QIcon(":/images/new.png"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new spreadsheet file"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    openAction = new QAction(tr("&Open"), this);
    openAction->setIcon(QIcon(":/images/open.png"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open a new spreadsheet file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon(":/images/save.png"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("save a file to the disk"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAction = new QAction(tr("Save &As..."), this);
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    saveAsAction->setStatusTip(tr("Save as a file"));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));


    for(int i = 0; i < MaxRecentFiles; ++i){
        recentFileActions[i] = new QAction(this);
        recentFileActions[i]->setVisible(false);
        connect(recentFileActions[i], SIGNAL(triggered()), this, SLOT(openRecentFile()));
    }

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));


    cutAction = new QAction(tr("Cu&t"), this);
    cutAction->setIcon(QIcon(":/images/cut.png"));
    cutAction->setShortcut(QKeySequence::Cut);
    //cutAction->setStatusTip(tr("cut a file"));
    connect(cutAction, SIGNAL(triggered(bool)), spreadsheet, SLOT(cut()));

    copyAction = new QAction(tr("&copy"), this);
    copyAction->setIcon(QIcon(":/images/copy.png"));
    copyAction->setShortcut(QKeySequence::Copy);
    //copyAction->setStatusTip(tr("copy a file"));
    connect(copyAction, SIGNAL(triggered(bool)), spreadsheet, SLOT(copy()));

    pasteAction = new QAction(tr("&Paste"), this);
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setIcon(QIcon(":/images/paste.png"));
    //pasteAction->setStatusTip(tr("Paste a file"));
    connect(pasteAction, SIGNAL(triggered(bool)), spreadsheet, SLOT(paste()));

    deleteAction = new QAction(tr("&Delete"), this);
    deleteAction->setIcon(QIcon(":/images/delete.png"));
    deleteAction->setShortcut(QKeySequence::Delete);
    //deleteAction->setStatusTip(tr("delete a file"));
    connect(deleteAction, SIGNAL(triggered(bool)), spreadsheet, SLOT(del()));

    selectRowAction = new QAction(tr("&Row"), this);
    selectRowAction->setStatusTip(tr("select a row"));
    connect(selectRowAction, SIGNAL(triggered()), spreadsheet, SLOT(selectCurrentRow()));

    selectColumnAction = new QAction(tr("&Column"), this);
    selectColumnAction->setStatusTip(tr("select a column"));
    connect(selectColumnAction, SIGNAL(triggered()), spreadsheet, SLOT(selectCurrentColumn()));


    selectAllAction = new QAction(tr("&All"), this);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    selectAllAction->setStatusTip(tr("Select all the cells in the spreadsheet"));
    connect(selectAllAction, SIGNAL(triggered()), spreadsheet, SLOT(selectAll()));


    selectAction = new QAction(tr("&select"), this);
    selectAction->setStatusTip(tr("select all, or a row, a column"));

    findAction = new QAction(tr("&find"), this);
    findAction->setIcon(QIcon(":/images/find.png"));
    findAction->setShortcut(QKeySequence::Find);
    findAction->setStatusTip(tr("find a file"));
    connect(findAction, SIGNAL(triggered()), this, SLOT(find()));

    goToCellAction = new QAction(tr("&Go to Cell..."), this);
    goToCellAction->setShortcut(tr("Ctrl+G"));
    goToCellAction->setIcon(QIcon(":/images/gotocell.png"));
    goToCellAction->setStatusTip(tr("find as a file"));
    connect(goToCellAction, SIGNAL(triggered()), this, SLOT(goToCell()));

    recalculateAction = new QAction(tr("&Recalculate"), this);
    recalculateAction->setShortcut(tr("F9"));
    connect(recalculateAction, SIGNAL(triggered()), spreadsheet, SLOT(recalculate()));


    sortAction = new QAction(tr("&Sort"), this);
    sortAction->setStatusTip(tr("Sort the grid"));
    connect(sortAction, SIGNAL(triggered()), this, SLOT(sort));

    showGridAction = new QAction(tr("&Show Grid"), this);
    showGridAction->setCheckable(true);
    showGridAction->setChecked(spreadsheet->showGrid());
    showGridAction->setChecked(true);
    showGridAction->setStatusTip(tr("Show or hide the spreadsheet's grid"));
    connect(showGridAction, SIGNAL(toggled(bool)), spreadsheet, SLOT(setShowGrid(bool)));

    autoRecalculateAction = new QAction(tr("&Auto-Recalculate"), this);
    autoRecalculateAction->setChecked(true);
    autoRecalculateAction->setStatusTip(tr(" Auto-Recalculate spreadsheet file"));
    connect(autoRecalculateAction, SIGNAL(toggled(bool)), spreadsheet, SLOT(setAutoRecalculate(bool)));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's about box"));
  //  connect(aboutAction, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()));

    aboutAction = new QAction(tr("About &Qt"), this);
    aboutAction->setIcon(QIcon(":/images/aboutQt.png"));
    connect(aboutAction, SIGNAL(toggled(bool)), this, SLOT(about()));

   // aboutQtAction->setShortcut(QKeySequence:);
    aboutQtAction->setStatusTip(tr("about spreadsheet"));


}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    separatorAction = fileMenu->addSeparator();
    for(int i = 0; i < MaxRecentFiles; ++i)
        fileMenu->addAction(recentFileActions[i]);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(deleteAction);

    selectSubMenu = editMenu->addMenu(tr("&Select"));
    selectSubMenu->addAction(selectRowAction);
    selectSubMenu->addAction(selectColumnAction);
    selectSubMenu->addAction(selectAllAction);

    editMenu->addSeparator();
    editMenu->addAction(findAction);
    editMenu->addAction(goToCellAction);

    toolsMenu = menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(recalculateAction);
    toolsMenu->addAction(sortAction);

    optionsMenu = menuBar()->addMenu(tr("&Options"));
    optionsMenu->addAction(showGridAction);
    optionsMenu->addAction(autoRecalculateAction);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}

void MainWindow::createContextMenu()
{
    spreadsheet->addAction(cutAction);
    spreadsheet->addAction(copyAction);
    spreadsheet->addAction(pasteAction);
    spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createToolbars()
{
    fileToolbar = addToolBar(tr("&File"));
    fileToolbar->addAction(newAction);
    fileToolbar->addAction(openAction);
    fileToolbar->addAction(saveAction);

    editToolbar = addToolBar(tr("&Edit"));
    editToolbar->addAction(cutAction);
    editToolbar->addAction(copyAction);
    editToolbar->addAction(pasteAction);
    editToolbar->addSeparator();
    editToolbar->addAction(findAction);
    editToolbar->addAction(goToCellAction);
}

void MainWindow::createStatusBar()
{
    locationLabel = new QLabel(" W999 ");
    locationLabel->setAlignment(Qt::AlignHCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    formulaLabel = new QLabel;
    formulaLabel->setIndent(3);

    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(formulaLabel, 1);

    connect(spreadsheet, SIGNAL(currentCellChanged(int, int, int, int)),
            this, SLOT(spreadsheetModified()));

    updateStatusBar();
}

void MainWindow::readSettings()
{
    QSettings settings("Software Inc.", "Spreadsheet");
    restoreGeometry(settings.value("geometry").toByteArray());
    recentFiles = settings.value("recentFiles").toStringList();
    updateRecentFileActions();

    bool showGrid = settings.value("showGrid").toBool();
    showGridAction->setChecked(showGrid);

    bool autoReCalc = settings.value("autoReCalc", true).toBool();
    autoRecalculateAction->setChecked(autoReCalc);
}

void MainWindow::writeSetting()
{
    QSettings settings("Software Inc.", "Spreadsheet");

    settings.setValue("geometry", saveGeometry());
    settings.setValue("recentFiles", recentFiles);
    settings.setValue("showGrid", showGridAction->isChecked());
    settings.setValue("autorecalc", autoRecalculateAction->isChecked());
}

bool MainWindow::okToContinu()
{
    if(isWindowModified()){
        int r = QMessageBox::warning(this, tr("Spreadsheet"),
               tr("The document has been modified.\n"
                    "Do you want to save your changes?"),
            QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if(r == QMessageBox::Yes)
            return save();
        else if (r == QMessageBox::Cancel){
            return false;
        }
    }
    return true;
}

bool MainWindow::loadFile(const QString &filename)
{
    if(!spreadsheet->readFile(filename)){
        statusBar()->showMessage(tr("Loading canceled"), 2000);
        return false;
    }

    setCurrentFile(filename);
    statusBar()->showMessage(tr("File Loaded"), 2000);
    return true;
}

bool MainWindow::saveFile(const QString &filename)
{
    if(!spreadsheet->writeFile(filename)){
        statusBar()->showMessage(tr("Saving canceled"), 2000);
        return false;
    }

    setCurrentFile(filename);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void MainWindow::setCurrentFile(const QString &filename)
{
    curFile = filename;
    setWindowModified(false);

    QString showName = tr("Untitle");
    if(!curFile.isEmpty()){
        showName = strippedName(curFile);
        recentFiles.removeAll(curFile);
        recentFiles.prepend(curFile);
        updateRecentFileActions();
    }
    setWindowTitle(tr("%1[*] - %2").arg(showName).arg(tr("Spreadsheet")));
}

void MainWindow::updateRecentFileActions()
{
    QMutableStringListIterator i(recentFiles);
    while(i.hasNext())
        if(!QFile::exists(i.next()))
            i.remove();

    for(int j = 0; j < MaxRecentFiles; ++j){
        if(j < recentFiles.count()){
            QString text = tr("&%1 %2")
                            .arg(j + 1)
                               .arg(strippedName(recentFiles[j]));
            recentFileActions[j]->setText(text);
            recentFileActions[j]->setData(recentFiles[j]);
            recentFileActions[j]->setVisible(true);
        }
        else
            recentFileActions[j]->setVisible(false);
    }
    separatorAction->setVisible(!recentFiles.isEmpty());
}

QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

void MainWindow::updateStatusBar()
{
    locationLabel->setText(spreadsheet->currentLocation());
    formulaLabel->setText(spreadsheet->currentFormula());
}

void MainWindow::spreadsheetModified()
{
    setWindowModified(true);
    updateStatusBar();
}

