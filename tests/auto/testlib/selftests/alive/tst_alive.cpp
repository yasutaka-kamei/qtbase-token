begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|"qtestalive.cpp"
end_include
begin_class
DECL|class|tst_Alive
class|class
name|tst_Alive
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|alive
parameter_list|()
function_decl|;
name|void
name|addMouseDClick
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|alive
name|void
name|tst_Alive
operator|::
name|alive
parameter_list|()
block|{
name|QTestAlive
name|a
decl_stmt|;
name|a
operator|.
name|start
argument_list|()
expr_stmt|;
name|sleep
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|qDebug
argument_list|(
literal|"CUT"
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|5
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addMouseDClick
name|void
name|tst_Alive
operator|::
name|addMouseDClick
parameter_list|()
specifier|const
block|{
class|class
name|DClickListener
super|:
specifier|public
name|QWidget
block|{
public|public:
name|DClickListener
parameter_list|()
member_init_list|:
name|isTested
argument_list|(
literal|false
argument_list|)
block|{         }
name|bool
name|isTested
decl_stmt|;
protected|protected:
specifier|virtual
name|void
name|mouseDoubleClickEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|isTested
operator|=
literal|true
expr_stmt|;
name|QCOMPARE
argument_list|(
name|event
operator|->
name|type
argument_list|()
argument_list|,
name|QEvent
operator|::
name|MouseButtonDblClick
argument_list|)
expr_stmt|;
block|}
block|}
class|;
name|DClickListener
name|listener
decl_stmt|;
name|QTestEventList
name|list
decl_stmt|;
name|list
operator|.
name|addMouseDClick
argument_list|(
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|list
operator|.
name|simulate
argument_list|(
operator|&
name|listener
argument_list|)
expr_stmt|;
comment|/* Check that we have been called at all. */
name|QVERIFY
argument_list|(
name|listener
operator|.
name|isTested
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_Alive
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_alive.moc"
end_include
end_unit
