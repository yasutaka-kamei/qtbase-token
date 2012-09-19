begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qabstractprintdialog_p.h"
end_include
begin_include
include|#
directive|include
file|"qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|"qprintdialog.h"
end_include
begin_include
include|#
directive|include
file|"qprinter.h"
end_include
begin_include
include|#
directive|include
file|"private/qprinter_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTDIALOG
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// hack
end_comment
begin_class
DECL|class|QPrintDialogPrivate
class|class
name|QPrintDialogPrivate
super|:
specifier|public
name|QAbstractPrintDialogPrivate
block|{
block|}
class|;
end_class
begin_comment
comment|/*!     \class QAbstractPrintDialog     \brief The QAbstractPrintDialog class provides a base implementation for     print dialogs used to configure printers.      \ingroup printing     \inmodule QtPrintSupport      This class implements getter and setter functions that are used to     customize settings shown in print dialogs, but it is not used directly.     Use QPrintDialog to display a print dialog in your application.      \sa QPrintDialog, QPrinter, {Printing with Qt} */
end_comment
begin_comment
comment|/*!     \enum QAbstractPrintDialog::PrintRange      Used to specify the print range selection option.      \value AllPages All pages should be printed.     \value Selection Only the selection should be printed.     \value PageRange The specified page range should be printed.     \value CurrentPage Only the currently visible page should be printed.      \sa QPrinter::PrintRange */
end_comment
begin_comment
comment|/*!     \enum QAbstractPrintDialog::PrintDialogOption      Used to specify which parts of the print dialog should be visible.      \value None None of the options are enabled.     \value PrintToFile The print to file option is enabled.     \value PrintSelection The print selection option is enabled.     \value PrintPageRange The page range selection option is enabled.     \value PrintShowPageSize  Show the page size + margins page only if this is enabled.     \value PrintCollateCopies The collate copies option is enabled     \value PrintCurrentPage The print current page option is enabled      This value is obsolete and does nothing since Qt 4.5:      \value DontUseSheet In previous versions of Qt, exec() the print dialog     would create a sheet by default the dialog was given a parent.     This is no longer supported in Qt 4.5.  If you want to use sheets, use     QPrintDialog::open() instead. */
end_comment
begin_comment
comment|/*!     Constructs an abstract print dialog for \a printer with \a parent     as parent widget. */
end_comment
begin_constructor
DECL|function|QAbstractPrintDialog
name|QAbstractPrintDialog
operator|::
name|QAbstractPrintDialog
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
operator|*
operator|(
operator|new
name|QAbstractPrintDialogPrivate
operator|)
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QPrintDialog"
argument_list|,
literal|"Print"
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|setPrinter
argument_list|(
name|printer
argument_list|)
expr_stmt|;
name|d
operator|->
name|minPage
operator|=
name|printer
operator|->
name|fromPage
argument_list|()
expr_stmt|;
name|int
name|to
init|=
name|printer
operator|->
name|toPage
argument_list|()
decl_stmt|;
name|d
operator|->
name|maxPage
operator|=
name|to
operator|>
literal|0
condition|?
name|to
else|:
name|INT_MAX
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!      \internal */
end_comment
begin_constructor
DECL|function|QAbstractPrintDialog
name|QAbstractPrintDialog
operator|::
name|QAbstractPrintDialog
parameter_list|(
name|QAbstractPrintDialogPrivate
modifier|&
name|ptr
parameter_list|,
name|QPrinter
modifier|*
name|printer
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|ptr
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QPrintDialog"
argument_list|,
literal|"Print"
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|setPrinter
argument_list|(
name|printer
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_destructor
DECL|function|~QAbstractPrintDialog
name|QAbstractPrintDialog
operator|::
name|~
name|QAbstractPrintDialog
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|ownsPrinter
condition|)
operator|delete
name|d
operator|->
name|printer
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Sets the given \a option to be enabled if \a on is true;     otherwise, clears the given \a option.      \sa options, testOption() */
end_comment
begin_function
DECL|function|setOption
name|void
name|QPrintDialog
operator|::
name|setOption
parameter_list|(
name|PrintDialogOption
name|option
parameter_list|,
name|bool
name|on
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPrintDialog
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|d
operator|->
name|options
operator|&
name|option
operator|)
operator|!=
operator|!
name|on
condition|)
name|setOptions
argument_list|(
name|d
operator|->
name|options
operator|^
name|option
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the given \a option is enabled; otherwise, returns     false.      \sa options, setOption() */
end_comment
begin_function
DECL|function|testOption
name|bool
name|QPrintDialog
operator|::
name|testOption
parameter_list|(
name|PrintDialogOption
name|option
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPrintDialog
argument_list|)
expr_stmt|;
return|return
operator|(
name|d
operator|->
name|options
operator|&
name|option
operator|)
operator|!=
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     \property QPrintDialog::options     \brief the various options that affect the look and feel of the dialog     \since 4.5      By default, all options are disabled.      Options should be set before showing the dialog. Setting them while the     dialog is visible is not guaranteed to have an immediate effect on the     dialog (depending on the option and on the platform).      \sa setOption(), testOption() */
end_comment
begin_function
DECL|function|setOptions
name|void
name|QPrintDialog
operator|::
name|setOptions
parameter_list|(
name|PrintDialogOptions
name|options
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPrintDialog
argument_list|)
expr_stmt|;
name|PrintDialogOptions
name|changed
init|=
operator|(
name|options
operator|^
name|d
operator|->
name|options
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|changed
condition|)
return|return;
name|d
operator|->
name|options
operator|=
name|options
expr_stmt|;
block|}
end_function
begin_function
DECL|function|options
name|QPrintDialog
operator|::
name|PrintDialogOptions
name|QPrintDialog
operator|::
name|options
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPrintDialog
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|options
return|;
block|}
end_function
begin_comment
comment|/*!     \obsolete      Use QPrintDialog::setOptions() instead. */
end_comment
begin_function
DECL|function|setEnabledOptions
name|void
name|QAbstractPrintDialog
operator|::
name|setEnabledOptions
parameter_list|(
name|PrintDialogOptions
name|options
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
name|d
operator|->
name|options
operator|=
name|options
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \obsolete      Use QPrintDialog::setOption(\a option, true) instead. */
end_comment
begin_function
DECL|function|addEnabledOption
name|void
name|QAbstractPrintDialog
operator|::
name|addEnabledOption
parameter_list|(
name|PrintDialogOption
name|option
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
name|d
operator|->
name|options
operator||=
name|option
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \obsolete      Use QPrintDialog::options() instead. */
end_comment
begin_function
DECL|function|enabledOptions
name|QAbstractPrintDialog
operator|::
name|PrintDialogOptions
name|QAbstractPrintDialog
operator|::
name|enabledOptions
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|options
return|;
block|}
end_function
begin_comment
comment|/*!     \obsolete      Use QPrintDialog::testOption(\a option) instead. */
end_comment
begin_function
DECL|function|isOptionEnabled
name|bool
name|QAbstractPrintDialog
operator|::
name|isOptionEnabled
parameter_list|(
name|PrintDialogOption
name|option
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|options
operator|&
name|option
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the print range option in to be \a range.  */
end_comment
begin_function
DECL|function|setPrintRange
name|void
name|QAbstractPrintDialog
operator|::
name|setPrintRange
parameter_list|(
name|PrintRange
name|range
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
name|d
operator|->
name|printer
operator|->
name|setPrintRange
argument_list|(
name|QPrinter
operator|::
name|PrintRange
argument_list|(
name|range
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the print range. */
end_comment
begin_function
DECL|function|printRange
name|QAbstractPrintDialog
operator|::
name|PrintRange
name|QAbstractPrintDialog
operator|::
name|printRange
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
return|return
name|QAbstractPrintDialog
operator|::
name|PrintRange
argument_list|(
name|d
operator|->
name|pd
operator|->
name|printRange
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the page range in this dialog to be from \a min to \a max. This also     enables the PrintPageRange option. */
end_comment
begin_function
DECL|function|setMinMax
name|void
name|QAbstractPrintDialog
operator|::
name|setMinMax
parameter_list|(
name|int
name|min
parameter_list|,
name|int
name|max
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|min
operator|<=
name|max
argument_list|,
literal|"QAbstractPrintDialog::setMinMax"
argument_list|,
literal|"'min' must be less than or equal to 'max'"
argument_list|)
expr_stmt|;
name|d
operator|->
name|minPage
operator|=
name|min
expr_stmt|;
name|d
operator|->
name|maxPage
operator|=
name|max
expr_stmt|;
name|d
operator|->
name|options
operator||=
name|PrintPageRange
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the minimum page in the page range.     By default, this value is set to 1. */
end_comment
begin_function
DECL|function|minPage
name|int
name|QAbstractPrintDialog
operator|::
name|minPage
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|minPage
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the maximum page in the page range. As of Qt 4.4, this     function returns INT_MAX by default. Previous versions returned 1     by default. */
end_comment
begin_function
DECL|function|maxPage
name|int
name|QAbstractPrintDialog
operator|::
name|maxPage
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|maxPage
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the range in the print dialog to be from \a from to \a to. */
end_comment
begin_function
DECL|function|setFromTo
name|void
name|QAbstractPrintDialog
operator|::
name|setFromTo
parameter_list|(
name|int
name|from
parameter_list|,
name|int
name|to
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|from
operator|<=
name|to
argument_list|,
literal|"QAbstractPrintDialog::setFromTo"
argument_list|,
literal|"'from' must be less than or equal to 'to'"
argument_list|)
expr_stmt|;
name|d
operator|->
name|printer
operator|->
name|setFromTo
argument_list|(
name|from
argument_list|,
name|to
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|minPage
operator|==
literal|0
operator|&&
name|d
operator|->
name|maxPage
operator|==
literal|0
condition|)
name|setMinMax
argument_list|(
literal|1
argument_list|,
name|to
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the first page to be printed     By default, this value is set to 0. */
end_comment
begin_function
DECL|function|fromPage
name|int
name|QAbstractPrintDialog
operator|::
name|fromPage
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|printer
operator|->
name|fromPage
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the last page to be printed.     By default, this value is set to 0. */
end_comment
begin_function
DECL|function|toPage
name|int
name|QAbstractPrintDialog
operator|::
name|toPage
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|printer
operator|->
name|toPage
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the printer that this printer dialog operates     on. */
end_comment
begin_function
DECL|function|printer
name|QPrinter
modifier|*
name|QAbstractPrintDialog
operator|::
name|printer
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|printer
return|;
block|}
end_function
begin_function
DECL|function|setPrinter
name|void
name|QAbstractPrintDialogPrivate
operator|::
name|setPrinter
parameter_list|(
name|QPrinter
modifier|*
name|newPrinter
parameter_list|)
block|{
if|if
condition|(
name|newPrinter
condition|)
block|{
name|printer
operator|=
name|newPrinter
expr_stmt|;
name|ownsPrinter
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|printer
operator|->
name|fromPage
argument_list|()
operator|||
name|printer
operator|->
name|toPage
argument_list|()
condition|)
name|options
operator||=
name|QAbstractPrintDialog
operator|::
name|PrintPageRange
expr_stmt|;
block|}
else|else
block|{
name|printer
operator|=
operator|new
name|QPrinter
expr_stmt|;
name|ownsPrinter
operator|=
literal|true
expr_stmt|;
block|}
name|pd
operator|=
name|printer
operator|->
name|d_func
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn int QAbstractPrintDialog::exec()      This virtual function is called to pop up the dialog. It must be     reimplemented in subclasses. */
end_comment
begin_comment
comment|/*!     \class QPrintDialog      \brief The QPrintDialog class provides a dialog for specifying     the printer's configuration.      \ingroup standard-dialogs     \ingroup printing     \inmodule QtPrintSupport      The dialog allows users to change document-related settings, such     as the paper size and orientation, type of print (color or     grayscale), range of pages, and number of copies to print.      Controls are also provided to enable users to choose from the     printers available, including any configured network printers.      Typically, QPrintDialog objects are constructed with a QPrinter     object, and executed using the exec() function.      \snippet code/src_gui_dialogs_qabstractprintdialog.cpp 0      If the dialog is accepted by the user, the QPrinter object is     correctly configured for printing.      \table     \row     \li \inlineimage plastique-printdialog.png     \li \inlineimage plastique-printdialog-properties.png     \endtable      The printer dialog (shown above in Plastique style) enables access to common     printing properties. On X11 platforms that use the CUPS printing system, the     settings for each available printer can be modified via the dialog's     \uicontrol{Properties} push button.      On Windows and Mac OS X, the native print dialog is used, which means that     some QWidget and QDialog properties set on the dialog won't be respected.     The native print dialog on Mac OS X does not support setting printer options,     i.e. setOptions() and setOption() have no effect.      In Qt 4.4, it was possible to use the static functions to show a sheet on     Mac OS X. This is no longer supported in Qt 4.5. If you want this     functionality, use QPrintDialog::open().      \sa QPageSetupDialog, QPrinter, {Pixelator Example}, {Order Form Example},         {Image Viewer Example}, {Scribble Example} */
end_comment
begin_comment
comment|/*!     \fn QPrintDialog::QPrintDialog(QPrinter *printer, QWidget *parent)      Constructs a new modal printer dialog for the given \a printer     with the given \a parent. */
end_comment
begin_comment
comment|/*!     \fn QPrintDialog::~QPrintDialog()      Destroys the print dialog. */
end_comment
begin_comment
comment|/*!     \fn int QPrintDialog::exec()     \reimp */
end_comment
begin_comment
comment|/*!     \since 4.4      Set a list of widgets as \a tabs to be shown on the print dialog, if supported.      Currently this option is only supported on X11.      Setting the option tabs will transfer their ownership to the print dialog. */
end_comment
begin_function
DECL|function|setOptionTabs
name|void
name|QAbstractPrintDialog
operator|::
name|setOptionTabs
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QWidget
modifier|*
argument_list|>
modifier|&
name|tabs
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractPrintDialog
argument_list|)
expr_stmt|;
name|d
operator|->
name|setTabs
argument_list|(
name|tabs
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!      \fn void QPrintDialog::accepted(QPrinter *printer)      This signal is emitted when the user accepts the values set in the print dialog.     The \a printer parameter includes the printer that the settings were applied to. */
end_comment
begin_comment
comment|/*!     \fn QPrinter *QPrintDialog::printer()      Returns the printer that this printer dialog operates     on. This can be useful when using the QPrintDialog::open() method. */
end_comment
begin_comment
comment|/*!   Closes the dialog and sets its result code to \a result. If this dialog   is shown with exec(), done() causes the local event loop to finish,   and exec() to return \a result.    \sa QDialog::done() */
end_comment
begin_function
DECL|function|done
name|void
name|QPrintDialog
operator|::
name|done
parameter_list|(
name|int
name|result
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPrintDialog
argument_list|)
expr_stmt|;
name|QDialog
operator|::
name|done
argument_list|(
name|result
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|==
name|Accepted
condition|)
emit|emit
name|accepted
argument_list|(
name|printer
argument_list|()
argument_list|)
emit|;
if|if
condition|(
name|d
operator|->
name|receiverToDisconnectOnClose
condition|)
block|{
name|disconnect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|(
name|QPrinter
operator|*
argument_list|)
argument_list|)
argument_list|,
name|d
operator|->
name|receiverToDisconnectOnClose
argument_list|,
name|d
operator|->
name|memberToDisconnectOnClose
argument_list|)
expr_stmt|;
name|d
operator|->
name|receiverToDisconnectOnClose
operator|=
literal|0
expr_stmt|;
block|}
name|d
operator|->
name|memberToDisconnectOnClose
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 4.5     \overload      Opens the dialog and connects its accepted() signal to the slot specified     by \a receiver and \a member.      The signal will be disconnected from the slot when the dialog is closed. */
end_comment
begin_function
DECL|function|open
name|void
name|QPrintDialog
operator|::
name|open
parameter_list|(
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPrintDialog
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|(
name|QPrinter
operator|*
argument_list|)
argument_list|)
argument_list|,
name|receiver
argument_list|,
name|member
argument_list|)
expr_stmt|;
name|d
operator|->
name|receiverToDisconnectOnClose
operator|=
name|receiver
expr_stmt|;
name|d
operator|->
name|memberToDisconnectOnClose
operator|=
name|member
expr_stmt|;
name|QDialog
operator|::
name|open
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTDIALOG
end_comment
end_unit
