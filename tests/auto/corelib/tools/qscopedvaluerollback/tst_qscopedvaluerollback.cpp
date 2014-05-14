begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedValueRollback>
end_include
begin_comment
comment|/*!  \class tst_QScopedValueRollback  \internal  \since 4.8  \brief Tests class QScopedValueRollback.   */
end_comment
begin_class
DECL|class|tst_QScopedValueRollback
class|class
name|tst_QScopedValueRollback
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|Q_SLOTS
private|:
name|void
name|leavingScope
parameter_list|()
function_decl|;
name|void
name|leavingScopeAfterCommit
parameter_list|()
function_decl|;
name|void
name|rollbackToPreviousCommit
parameter_list|()
function_decl|;
name|void
name|exceptions
parameter_list|()
function_decl|;
name|void
name|earlyExitScope
parameter_list|()
function_decl|;
private|private:
name|void
name|earlyExitScope_helper
parameter_list|(
name|int
name|exitpoint
parameter_list|,
name|int
modifier|&
name|member
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|leavingScope
name|void
name|tst_QScopedValueRollback
operator|::
name|leavingScope
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
name|bool
name|b
init|=
literal|false
decl_stmt|;
name|bool
name|b2
init|=
literal|false
decl_stmt|;
name|QString
name|s
argument_list|(
literal|"This is useful"
argument_list|)
decl_stmt|;
comment|//test rollback on going out of scope
block|{
name|QScopedValueRollback
argument_list|<
name|int
argument_list|>
name|ri
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QScopedValueRollback
argument_list|<
name|bool
argument_list|>
name|rb
argument_list|(
name|b
argument_list|)
decl_stmt|;
name|QScopedValueRollback
argument_list|<
name|bool
argument_list|>
name|rb2
argument_list|(
name|b2
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|QScopedValueRollback
argument_list|<
name|QString
argument_list|>
name|rs
argument_list|(
name|s
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|b
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|b2
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s
argument_list|,
name|QString
argument_list|(
literal|"This is useful"
argument_list|)
argument_list|)
expr_stmt|;
name|b
operator|=
literal|true
expr_stmt|;
name|i
operator|=
literal|1
expr_stmt|;
name|s
operator|=
literal|"Useless"
expr_stmt|;
name|QCOMPARE
argument_list|(
name|b
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s
argument_list|,
name|QString
argument_list|(
literal|"Useless"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|b
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|b2
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s
argument_list|,
name|QString
argument_list|(
literal|"This is useful"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|leavingScopeAfterCommit
name|void
name|tst_QScopedValueRollback
operator|::
name|leavingScopeAfterCommit
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
name|bool
name|b
init|=
literal|false
decl_stmt|;
name|QString
name|s
argument_list|(
literal|"This is useful"
argument_list|)
decl_stmt|;
comment|//test rollback on going out of scope
block|{
name|QScopedValueRollback
argument_list|<
name|int
argument_list|>
name|ri
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QScopedValueRollback
argument_list|<
name|bool
argument_list|>
name|rb
argument_list|(
name|b
argument_list|)
decl_stmt|;
name|QScopedValueRollback
argument_list|<
name|QString
argument_list|>
name|rs
argument_list|(
name|s
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|b
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s
argument_list|,
name|QString
argument_list|(
literal|"This is useful"
argument_list|)
argument_list|)
expr_stmt|;
name|b
operator|=
literal|true
expr_stmt|;
name|i
operator|=
literal|1
expr_stmt|;
name|s
operator|=
literal|"Useless"
expr_stmt|;
name|QCOMPARE
argument_list|(
name|b
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s
argument_list|,
name|QString
argument_list|(
literal|"Useless"
argument_list|)
argument_list|)
expr_stmt|;
name|ri
operator|.
name|commit
argument_list|()
expr_stmt|;
name|rb
operator|.
name|commit
argument_list|()
expr_stmt|;
name|rs
operator|.
name|commit
argument_list|()
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|b
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s
argument_list|,
name|QString
argument_list|(
literal|"Useless"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rollbackToPreviousCommit
name|void
name|tst_QScopedValueRollback
operator|::
name|rollbackToPreviousCommit
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
block|{
name|QScopedValueRollback
argument_list|<
name|int
argument_list|>
name|ri
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|i
operator|++
expr_stmt|;
name|ri
operator|.
name|commit
argument_list|()
expr_stmt|;
name|i
operator|++
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|{
name|QScopedValueRollback
argument_list|<
name|int
argument_list|>
name|ri1
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|i
operator|++
expr_stmt|;
name|ri1
operator|.
name|commit
argument_list|()
expr_stmt|;
name|i
operator|++
expr_stmt|;
name|ri1
operator|.
name|commit
argument_list|()
expr_stmt|;
name|i
operator|++
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|exceptions
name|void
name|tst_QScopedValueRollback
operator|::
name|exceptions
parameter_list|()
block|{
name|bool
name|b
init|=
literal|false
decl_stmt|;
name|bool
name|caught
init|=
literal|false
decl_stmt|;
name|QT_TRY
block|{
name|QScopedValueRollback
argument_list|<
name|bool
argument_list|>
name|rb
argument_list|(
name|b
argument_list|)
decl_stmt|;
name|b
operator|=
literal|true
expr_stmt|;
name|QT_THROW
argument_list|(
name|std
operator|::
name|bad_alloc
argument_list|()
argument_list|)
expr_stmt|;
comment|//if Qt compiled without exceptions this is noop
name|rb
operator|.
name|commit
argument_list|()
expr_stmt|;
comment|//if Qt compiled without exceptions, true is committed
block|}
name|QT_CATCH
argument_list|(
argument|...
argument_list|)
block|{
name|caught
operator|=
literal|true
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|b
argument_list|,
operator|!
name|caught
argument_list|)
expr_stmt|;
comment|//expect false if exception was thrown, true otherwise
block|}
end_function
begin_function
DECL|function|earlyExitScope
name|void
name|tst_QScopedValueRollback
operator|::
name|earlyExitScope
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
name|int
name|j
init|=
literal|0
decl_stmt|;
while|while
condition|(
literal|true
condition|)
block|{
name|QScopedValueRollback
argument_list|<
name|int
argument_list|>
name|ri
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|i
operator|++
expr_stmt|;
name|j
operator|=
name|i
expr_stmt|;
if|if
condition|(
name|i
operator|>
literal|8
condition|)
break|break;
name|ri
operator|.
name|commit
argument_list|()
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|j
argument_list|,
literal|9
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|5
condition|;
name|i
operator|++
control|)
block|{
name|j
operator|=
literal|1
expr_stmt|;
name|earlyExitScope_helper
argument_list|(
name|i
argument_list|,
name|j
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|j
argument_list|,
literal|1
operator|<<
name|i
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|earlyExitScope_helper
name|void
name|tst_QScopedValueRollback
operator|::
name|earlyExitScope_helper
parameter_list|(
name|int
name|exitpoint
parameter_list|,
name|int
modifier|&
name|member
parameter_list|)
block|{
name|QScopedValueRollback
argument_list|<
name|int
argument_list|>
name|r
argument_list|(
name|member
argument_list|)
decl_stmt|;
name|member
operator|*=
literal|2
expr_stmt|;
if|if
condition|(
name|exitpoint
operator|==
literal|0
condition|)
return|return;
name|r
operator|.
name|commit
argument_list|()
expr_stmt|;
name|member
operator|*=
literal|2
expr_stmt|;
if|if
condition|(
name|exitpoint
operator|==
literal|1
condition|)
return|return;
name|r
operator|.
name|commit
argument_list|()
expr_stmt|;
name|member
operator|*=
literal|2
expr_stmt|;
if|if
condition|(
name|exitpoint
operator|==
literal|2
condition|)
return|return;
name|r
operator|.
name|commit
argument_list|()
expr_stmt|;
name|member
operator|*=
literal|2
expr_stmt|;
if|if
condition|(
name|exitpoint
operator|==
literal|3
condition|)
return|return;
name|r
operator|.
name|commit
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QScopedValueRollback
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qscopedvaluerollback.moc"
end_include
end_unit
