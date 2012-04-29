begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFileInfo>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDir>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QClipboard>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_include
include|#
directive|include
file|<Carbon/Carbon.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_QClipboard
class|class
name|tst_QClipboard
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|copy_exit_paste
parameter_list|()
function_decl|;
name|void
name|capabilityFunctions
parameter_list|()
function_decl|;
name|void
name|modes
parameter_list|()
function_decl|;
name|void
name|testSignals
parameter_list|()
function_decl|;
name|void
name|setMimeData
parameter_list|()
function_decl|;
name|void
name|clearBeforeSetText
parameter_list|()
function_decl|;
private|private:
name|bool
name|nativeClipboardWorking
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|init
name|void
name|tst_QClipboard
operator|::
name|init
parameter_list|()
block|{
specifier|const
name|QString
name|testdataDir
init|=
name|QFileInfo
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"copier"
argument_list|)
argument_list|)
operator|.
name|absolutePath
argument_list|()
decl_stmt|;
name|QVERIFY2
argument_list|(
name|QDir
operator|::
name|setCurrent
argument_list|(
name|testdataDir
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
literal|"Could not chdir to "
operator|+
name|testdataDir
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nativeClipboardWorking
name|bool
name|tst_QClipboard
operator|::
name|nativeClipboardWorking
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|PasteboardRef
name|pasteboard
decl_stmt|;
name|OSStatus
name|status
init|=
name|PasteboardCreate
argument_list|(
literal|0
argument_list|,
operator|&
name|pasteboard
argument_list|)
decl_stmt|;
if|if
condition|(
name|status
operator|==
name|noErr
condition|)
name|CFRelease
argument_list|(
name|pasteboard
argument_list|)
expr_stmt|;
return|return
name|status
operator|==
name|noErr
return|;
endif|#
directive|endif
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QClipboard::Mode
argument_list|)
end_macro
begin_comment
comment|/*     Tests that the capability functions are implemented on all     platforms. */
end_comment
begin_function
DECL|function|capabilityFunctions
name|void
name|tst_QClipboard
operator|::
name|capabilityFunctions
parameter_list|()
block|{
name|QClipboard
modifier|*
specifier|const
name|clipboard
init|=
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
decl_stmt|;
name|clipboard
operator|->
name|supportsSelection
argument_list|()
expr_stmt|;
name|clipboard
operator|->
name|supportsFindBuffer
argument_list|()
expr_stmt|;
name|clipboard
operator|->
name|ownsSelection
argument_list|()
expr_stmt|;
name|clipboard
operator|->
name|ownsClipboard
argument_list|()
expr_stmt|;
name|clipboard
operator|->
name|ownsFindBuffer
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Test that text inserted into the clipboard in different modes is     kept separate. */
end_comment
begin_function
DECL|function|modes
name|void
name|tst_QClipboard
operator|::
name|modes
parameter_list|()
block|{
name|QClipboard
modifier|*
specifier|const
name|clipboard
init|=
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|nativeClipboardWorking
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"Native clipboard not working in this setup"
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|defaultMode
init|=
literal|"default mode text;"
decl_stmt|;
name|clipboard
operator|->
name|setText
argument_list|(
name|defaultMode
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|clipboard
operator|->
name|text
argument_list|()
argument_list|,
name|defaultMode
argument_list|)
expr_stmt|;
if|if
condition|(
name|clipboard
operator|->
name|supportsSelection
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|selectionMode
init|=
literal|"selection mode text"
decl_stmt|;
name|clipboard
operator|->
name|setText
argument_list|(
name|selectionMode
argument_list|,
name|QClipboard
operator|::
name|Selection
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|clipboard
operator|->
name|text
argument_list|(
name|QClipboard
operator|::
name|Selection
argument_list|)
argument_list|,
name|selectionMode
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|clipboard
operator|->
name|text
argument_list|()
argument_list|,
name|defaultMode
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|clipboard
operator|->
name|supportsFindBuffer
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|searchMode
init|=
literal|"find mode text"
decl_stmt|;
name|clipboard
operator|->
name|setText
argument_list|(
name|searchMode
argument_list|,
name|QClipboard
operator|::
name|FindBuffer
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|clipboard
operator|->
name|text
argument_list|(
name|QClipboard
operator|::
name|FindBuffer
argument_list|)
argument_list|,
name|searchMode
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|clipboard
operator|->
name|text
argument_list|()
argument_list|,
name|defaultMode
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*     Test that the appropriate signals are emitted when the clipboard     contents is changed by calling the qt functions. */
end_comment
begin_function
DECL|function|testSignals
name|void
name|tst_QClipboard
operator|::
name|testSignals
parameter_list|()
block|{
name|qRegisterMetaType
argument_list|<
name|QClipboard
operator|::
name|Mode
argument_list|>
argument_list|(
literal|"QClipboard::Mode"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|nativeClipboardWorking
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"Native clipboard not working in this setup"
argument_list|)
expr_stmt|;
name|QClipboard
modifier|*
specifier|const
name|clipboard
init|=
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
decl_stmt|;
name|QSignalSpy
name|changedSpy
argument_list|(
name|clipboard
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|(
name|QClipboard
operator|::
name|Mode
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|dataChangedSpy
argument_list|(
name|clipboard
argument_list|,
name|SIGNAL
argument_list|(
name|dataChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|searchChangedSpy
argument_list|(
name|clipboard
argument_list|,
name|SIGNAL
argument_list|(
name|findBufferChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|selectionChangedSpy
argument_list|(
name|clipboard
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|text
init|=
literal|"clipboard text;"
decl_stmt|;
comment|// Test the default mode signal.
name|clipboard
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|dataChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|searchChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|selectionChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|changedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|changedSpy
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qvariant_cast
argument_list|<
name|QClipboard
operator|::
name|Mode
argument_list|>
argument_list|(
name|changedSpy
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
argument_list|,
name|QClipboard
operator|::
name|Clipboard
argument_list|)
expr_stmt|;
name|changedSpy
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// Test the selection mode signal.
if|if
condition|(
name|clipboard
operator|->
name|supportsSelection
argument_list|()
condition|)
block|{
name|clipboard
operator|->
name|setText
argument_list|(
name|text
argument_list|,
name|QClipboard
operator|::
name|Selection
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|selectionChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|changedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|changedSpy
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qvariant_cast
argument_list|<
name|QClipboard
operator|::
name|Mode
argument_list|>
argument_list|(
name|changedSpy
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
argument_list|,
name|QClipboard
operator|::
name|Selection
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QCOMPARE
argument_list|(
name|selectionChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|dataChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|searchChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|changedSpy
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// Test the search mode signal.
if|if
condition|(
name|clipboard
operator|->
name|supportsFindBuffer
argument_list|()
condition|)
block|{
name|clipboard
operator|->
name|setText
argument_list|(
name|text
argument_list|,
name|QClipboard
operator|::
name|FindBuffer
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|searchChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|changedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|changedSpy
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qvariant_cast
argument_list|<
name|QClipboard
operator|::
name|Mode
argument_list|>
argument_list|(
name|changedSpy
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
argument_list|,
name|QClipboard
operator|::
name|FindBuffer
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QCOMPARE
argument_list|(
name|searchChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|dataChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|runHelper
specifier|static
name|bool
name|runHelper
parameter_list|(
specifier|const
name|QString
modifier|&
name|program
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|arguments
parameter_list|,
name|QByteArray
modifier|*
name|errorMessage
parameter_list|)
block|{
name|QProcess
name|process
decl_stmt|;
name|process
operator|.
name|setReadChannelMode
argument_list|(
name|QProcess
operator|::
name|ForwardedChannels
argument_list|)
expr_stmt|;
name|process
operator|.
name|start
argument_list|(
name|program
argument_list|,
name|arguments
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|process
operator|.
name|waitForStarted
argument_list|()
condition|)
block|{
operator|*
name|errorMessage
operator|=
literal|"Unable to start '"
operator|+
name|program
operator|.
name|toLocal8Bit
argument_list|()
operator|+
literal|" ': "
operator|+
name|process
operator|.
name|errorString
argument_list|()
operator|.
name|toLocal8Bit
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Windows: Due to implementation changes, the event loop needs
comment|// to be spun since we ourselves also need to answer the
comment|// WM_DRAWCLIPBOARD message as we are in the chain of clipboard
comment|// viewers.
name|bool
name|running
init|=
literal|true
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|60
operator|&&
name|running
condition|;
operator|++
name|i
control|)
block|{
name|QGuiApplication
operator|::
name|processEvents
argument_list|(
name|QEventLoop
operator|::
name|ExcludeUserInputEvents
argument_list|)
expr_stmt|;
if|if
condition|(
name|process
operator|.
name|waitForFinished
argument_list|(
literal|500
argument_list|)
condition|)
name|running
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
name|running
condition|)
block|{
name|process
operator|.
name|kill
argument_list|()
expr_stmt|;
operator|*
name|errorMessage
operator|=
literal|"Timeout running '"
operator|+
name|program
operator|.
name|toLocal8Bit
argument_list|()
operator|+
literal|'\''
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|process
operator|.
name|exitStatus
argument_list|()
operator|!=
name|QProcess
operator|::
name|NormalExit
condition|)
block|{
operator|*
name|errorMessage
operator|=
literal|"Process '"
operator|+
name|program
operator|.
name|toLocal8Bit
argument_list|()
operator|+
literal|"' crashed."
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|process
operator|.
name|exitCode
argument_list|()
condition|)
block|{
operator|*
name|errorMessage
operator|=
literal|"Process '"
operator|+
name|program
operator|.
name|toLocal8Bit
argument_list|()
operator|+
literal|"' returns "
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|process
operator|.
name|exitCode
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|// Test that pasted text remains on the clipboard after a Qt application exits.
end_comment
begin_function
DECL|function|copy_exit_paste
name|void
name|tst_QClipboard
operator|::
name|copy_exit_paste
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_PROCESS
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
name|QSKIP
argument_list|(
literal|"This test does not make sense on X11 and embedded, copied data disappears from the clipboard when the application exits "
argument_list|)
expr_stmt|;
comment|// ### It's still possible to test copy/paste - just keep the apps running
endif|#
directive|endif
if|if
condition|(
operator|!
name|nativeClipboardWorking
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"Native clipboard not working in this setup"
argument_list|)
expr_stmt|;
specifier|const
name|QStringList
name|stringArgument
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Test string."
argument_list|)
argument_list|)
decl_stmt|;
name|QByteArray
name|errorMessage
decl_stmt|;
name|QVERIFY2
argument_list|(
name|runHelper
argument_list|(
name|QStringLiteral
argument_list|(
literal|"copier/copier"
argument_list|)
argument_list|,
name|stringArgument
argument_list|,
operator|&
name|errorMessage
argument_list|)
argument_list|,
name|errorMessage
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_MAC
comment|// The Pasteboard needs a moment to breathe (at least on older Macs).
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVERIFY2
argument_list|(
name|runHelper
argument_list|(
name|QStringLiteral
argument_list|(
literal|"paster/paster"
argument_list|)
argument_list|,
name|stringArgument
argument_list|,
operator|&
name|errorMessage
argument_list|)
argument_list|,
name|errorMessage
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|setMimeData
name|void
name|tst_QClipboard
operator|::
name|setMimeData
parameter_list|()
block|{
if|if
condition|(
operator|!
name|nativeClipboardWorking
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"Native clipboard not working in this setup"
argument_list|)
expr_stmt|;
name|QMimeData
modifier|*
name|mimeData
init|=
operator|new
name|QMimeData
decl_stmt|;
specifier|const
name|QString
name|TestName
argument_list|(
name|QLatin1String
argument_list|(
literal|"tst_QClipboard::setMimeData() mimeData"
argument_list|)
argument_list|)
decl_stmt|;
name|mimeData
operator|->
name|setObjectName
argument_list|(
name|TestName
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
comment|// need to set text on CE
name|mimeData
operator|->
name|setText
argument_list|(
name|QLatin1String
argument_list|(
literal|"Qt/CE foo"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setMimeData
argument_list|(
name|mimeData
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|mimeData
argument_list|()
argument_list|,
operator|(
specifier|const
name|QMimeData
operator|*
operator|)
name|mimeData
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|mimeData
argument_list|()
operator|->
name|objectName
argument_list|()
argument_list|,
name|TestName
argument_list|)
expr_stmt|;
comment|// set it to the same data again, it shouldn't delete mimeData (and crash as a result)
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setMimeData
argument_list|(
name|mimeData
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|mimeData
argument_list|()
argument_list|,
operator|(
specifier|const
name|QMimeData
operator|*
operator|)
name|mimeData
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|mimeData
argument_list|()
operator|->
name|objectName
argument_list|()
argument_list|,
name|TestName
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|clear
argument_list|()
expr_stmt|;
specifier|const
name|QMimeData
modifier|*
name|appMimeData
init|=
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|mimeData
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|appMimeData
operator|!=
name|mimeData
operator|||
name|appMimeData
operator|->
name|objectName
argument_list|()
operator|!=
name|TestName
argument_list|)
expr_stmt|;
comment|// check for crash when using the same mimedata object on several clipboards
name|QMimeData
modifier|*
name|data
init|=
operator|new
name|QMimeData
decl_stmt|;
name|data
operator|->
name|setText
argument_list|(
literal|"foo"
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setMimeData
argument_list|(
name|data
argument_list|,
name|QClipboard
operator|::
name|Clipboard
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setMimeData
argument_list|(
name|data
argument_list|,
name|QClipboard
operator|::
name|Selection
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setMimeData
argument_list|(
name|data
argument_list|,
name|QClipboard
operator|::
name|FindBuffer
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spySelection
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spyData
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|dataChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spyFindBuffer
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|findBufferChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|clear
argument_list|(
name|QClipboard
operator|::
name|Clipboard
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|clear
argument_list|(
name|QClipboard
operator|::
name|Selection
argument_list|)
expr_stmt|;
comment|// used to crash on X11
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|clear
argument_list|(
name|QClipboard
operator|::
name|FindBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|supportsSelection
argument_list|()
condition|)
name|QCOMPARE
argument_list|(
name|spySelection
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|spySelection
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|supportsFindBuffer
argument_list|()
condition|)
name|QCOMPARE
argument_list|(
name|spyFindBuffer
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|spyFindBuffer
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyData
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// an other crash test
name|data
operator|=
operator|new
name|QMimeData
expr_stmt|;
name|data
operator|->
name|setText
argument_list|(
literal|"foo"
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setMimeData
argument_list|(
name|data
argument_list|,
name|QClipboard
operator|::
name|Clipboard
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setMimeData
argument_list|(
name|data
argument_list|,
name|QClipboard
operator|::
name|Selection
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setMimeData
argument_list|(
name|data
argument_list|,
name|QClipboard
operator|::
name|FindBuffer
argument_list|)
expr_stmt|;
name|QMimeData
modifier|*
name|newData
init|=
operator|new
name|QMimeData
decl_stmt|;
name|newData
operator|->
name|setText
argument_list|(
literal|"bar"
argument_list|)
expr_stmt|;
name|spySelection
operator|.
name|clear
argument_list|()
expr_stmt|;
name|spyData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|spyFindBuffer
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setMimeData
argument_list|(
name|newData
argument_list|,
name|QClipboard
operator|::
name|Clipboard
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setMimeData
argument_list|(
name|newData
argument_list|,
name|QClipboard
operator|::
name|Selection
argument_list|)
expr_stmt|;
comment|// used to crash on X11
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setMimeData
argument_list|(
name|newData
argument_list|,
name|QClipboard
operator|::
name|FindBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|supportsSelection
argument_list|()
condition|)
name|QCOMPARE
argument_list|(
name|spySelection
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|spySelection
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|supportsFindBuffer
argument_list|()
condition|)
name|QCOMPARE
argument_list|(
name|spyFindBuffer
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|spyFindBuffer
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spyData
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clearBeforeSetText
name|void
name|tst_QClipboard
operator|::
name|clearBeforeSetText
parameter_list|()
block|{
name|QGuiApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|nativeClipboardWorking
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"Native clipboard not working in this setup"
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|text
init|=
literal|"tst_QClipboard::clearBeforeSetText()"
decl_stmt|;
comment|// setText() should work after processEvents()
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|text
argument_list|()
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|text
argument_list|()
argument_list|,
name|text
argument_list|)
expr_stmt|;
comment|// same with clear()
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|clear
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
comment|// setText() again
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|text
argument_list|()
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|text
argument_list|()
argument_list|,
name|text
argument_list|)
expr_stmt|;
comment|// clear() immediately followed by setText() should still return the text
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|clear
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|text
argument_list|()
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|text
argument_list|()
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QClipboard
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qclipboard.moc"
end_include
end_unit
