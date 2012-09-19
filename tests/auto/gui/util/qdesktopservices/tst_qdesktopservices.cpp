begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qdesktopservices.h>
end_include
begin_class
DECL|class|tst_qdesktopservices
class|class
name|tst_qdesktopservices
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_qdesktopservices
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_qdesktopservices
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
name|void
name|openUrl
parameter_list|()
function_decl|;
name|void
name|handlers
parameter_list|()
function_decl|;
name|void
name|testDataLocation
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_qdesktopservices
name|tst_qdesktopservices
operator|::
name|tst_qdesktopservices
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_qdesktopservices
name|tst_qdesktopservices
operator|::
name|~
name|tst_qdesktopservices
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|init
name|void
name|tst_qdesktopservices
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_qdesktopservices
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|openUrl
name|void
name|tst_qdesktopservices
operator|::
name|openUrl
parameter_list|()
block|{
comment|// At the bare minimum check that they return false for invalid url's
name|QCOMPARE
argument_list|(
name|QDesktopServices
operator|::
name|openUrl
argument_list|(
name|QUrl
argument_list|()
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
comment|// this test is only valid on windows on other systems it might mean open a new document in the application handling .file
name|QCOMPARE
argument_list|(
name|QDesktopServices
operator|::
name|openUrl
argument_list|(
name|QUrl
argument_list|(
literal|"file://invalid.file"
argument_list|)
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_class
DECL|class|MyUrlHandler
class|class
name|MyUrlHandler
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|member|lastHandledUrl
name|QUrl
name|lastHandledUrl
decl_stmt|;
public|public
name|slots
public|:
DECL|function|handle
specifier|inline
name|void
name|handle
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|lastHandledUrl
operator|=
name|url
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|handlers
name|void
name|tst_qdesktopservices
operator|::
name|handlers
parameter_list|()
block|{
name|MyUrlHandler
name|fooHandler
decl_stmt|;
name|MyUrlHandler
name|barHandler
decl_stmt|;
name|QDesktopServices
operator|::
name|setUrlHandler
argument_list|(
name|QString
argument_list|(
literal|"foo"
argument_list|)
argument_list|,
operator|&
name|fooHandler
argument_list|,
literal|"handle"
argument_list|)
expr_stmt|;
name|QDesktopServices
operator|::
name|setUrlHandler
argument_list|(
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|,
operator|&
name|barHandler
argument_list|,
literal|"handle"
argument_list|)
expr_stmt|;
name|QUrl
name|fooUrl
argument_list|(
literal|"foo://blub/meh"
argument_list|)
decl_stmt|;
name|QUrl
name|barUrl
argument_list|(
literal|"bar://hmm/hmmmm"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|QDesktopServices
operator|::
name|openUrl
argument_list|(
name|fooUrl
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QDesktopServices
operator|::
name|openUrl
argument_list|(
name|barUrl
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fooHandler
operator|.
name|lastHandledUrl
operator|.
name|toString
argument_list|()
argument_list|,
name|fooUrl
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|barHandler
operator|.
name|lastHandledUrl
operator|.
name|toString
argument_list|()
argument_list|,
name|barUrl
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_define
DECL|macro|Q_XDG_PLATFORM
define|#
directive|define
name|Q_XDG_PLATFORM
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|testDataLocation
name|void
name|tst_qdesktopservices
operator|::
name|testDataLocation
parameter_list|()
block|{
comment|// This is the one point where QDesktopServices and QStandardPaths differ.
comment|// QDesktopServices on unix returns "data"/orgname/appname for DataLocation, for Qt4 compat.
comment|// And the appname in qt4 defaulted to empty, not to argv[0].
block|{
specifier|const
name|QString
name|base
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|GenericDataLocation
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|app
init|=
name|QDesktopServices
operator|::
name|storageLocation
argument_list|(
name|QDesktopServices
operator|::
name|DataLocation
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_XDG_PLATFORM
name|QCOMPARE
argument_list|(
name|app
argument_list|,
name|base
operator|+
literal|"/data//"
argument_list|)
expr_stmt|;
comment|// as ugly as in Qt4
else|#
directive|else
name|QCOMPARE
argument_list|(
name|app
argument_list|,
name|base
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|setOrganizationName
argument_list|(
literal|"Qt"
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|setApplicationName
argument_list|(
literal|"QtTest"
argument_list|)
expr_stmt|;
block|{
specifier|const
name|QString
name|base
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|GenericDataLocation
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|app
init|=
name|QDesktopServices
operator|::
name|storageLocation
argument_list|(
name|QDesktopServices
operator|::
name|DataLocation
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_XDG_PLATFORM
name|QCOMPARE
argument_list|(
name|app
argument_list|,
name|base
operator|+
literal|"/data/Qt/QtTest"
argument_list|)
expr_stmt|;
else|#
directive|else
name|QCOMPARE
argument_list|(
name|app
argument_list|,
name|base
operator|+
literal|"/Qt/QtTest"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qdesktopservices
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qdesktopservices.moc"
end_include
end_unit
