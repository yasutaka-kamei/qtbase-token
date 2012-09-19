begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QExecStringList
class|class
name|tst_QExecStringList
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|testA
parameter_list|()
specifier|const
function_decl|;
name|void
name|testB
parameter_list|()
specifier|const
function_decl|;
name|void
name|testB_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|testC
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|testA
name|void
name|tst_QExecStringList
operator|::
name|testA
parameter_list|()
specifier|const
block|{ }
end_function
begin_function
DECL|function|testB
name|void
name|tst_QExecStringList
operator|::
name|testB
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|dummy
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|dummy
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testB_data
name|void
name|tst_QExecStringList
operator|::
name|testB_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"dummy"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Data1"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Data2"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Data3"
argument_list|)
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testC
name|void
name|tst_QExecStringList
operator|::
name|testC
parameter_list|()
specifier|const
block|{ }
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|tst_QExecStringList
name|test
decl_stmt|;
name|QTest
operator|::
name|qExec
argument_list|(
operator|&
name|test
argument_list|,
name|app
operator|.
name|arguments
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qExec
argument_list|(
operator|&
name|test
argument_list|,
name|QStringList
argument_list|(
literal|"appName"
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qExec
argument_list|(
operator|&
name|test
argument_list|,
name|QStringList
argument_list|(
literal|"appName"
argument_list|)
operator|<<
literal|"testA"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qExec
argument_list|(
operator|&
name|test
argument_list|,
name|QStringList
argument_list|(
literal|"appName"
argument_list|)
operator|<<
literal|"testB"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qExec
argument_list|(
operator|&
name|test
argument_list|,
name|QStringList
argument_list|(
literal|"appName"
argument_list|)
operator|<<
literal|"testB:Data2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qExec
argument_list|(
operator|&
name|test
argument_list|,
name|QStringList
argument_list|(
literal|"appName"
argument_list|)
operator|<<
literal|"testC"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"tst_qexecstringlist.moc"
end_include
end_unit
