begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_SkipInitData
class|class
name|tst_SkipInitData
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|initTestCase_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|initTestCase
parameter_list|()
specifier|const
function_decl|;
name|void
name|aTestFunction
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase_data
name|void
name|tst_SkipInitData
operator|::
name|initTestCase_data
parameter_list|()
specifier|const
block|{
name|QSKIP
argument_list|(
literal|"Skip inside initTestCase_data. This should skip all tests in the class."
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initTestCase
name|void
name|tst_SkipInitData
operator|::
name|initTestCase
parameter_list|()
specifier|const
block|{ }
end_function
begin_comment
comment|/*! \internal   This function should never be run because initTestCase fails.  */
end_comment
begin_function
DECL|function|aTestFunction
name|void
name|tst_SkipInitData
operator|::
name|aTestFunction
parameter_list|()
specifier|const
block|{
name|qDebug
argument_list|()
operator|<<
literal|"ERROR: this function is NOT supposed to be run."
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_SkipInitData
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_skipinitdata.moc"
end_include
end_unit
