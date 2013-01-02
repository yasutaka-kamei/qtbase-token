begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qmutex.h>
end_include
begin_include
include|#
directive|include
file|<qthread.h>
end_include
begin_include
include|#
directive|include
file|<qwaitcondition.h>
end_include
begin_include
include|#
directive|include
file|"qthreadonce.h"
end_include
begin_class
DECL|class|tst_QThreadOnce
class|class
name|tst_QThreadOnce
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|sameThread
parameter_list|()
function_decl|;
name|void
name|sameThread_data
parameter_list|()
function_decl|;
name|void
name|multipleThreads
parameter_list|()
function_decl|;
name|void
name|nesting
parameter_list|()
function_decl|;
name|void
name|reentering
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
name|void
name|exception
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
class|;
end_class
begin_class
DECL|class|SingletonObject
class|class
name|SingletonObject
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|member|runCount
specifier|static
name|int
name|runCount
decl_stmt|;
DECL|function|SingletonObject
name|SingletonObject
parameter_list|()
block|{
name|val
operator|.
name|store
argument_list|(
literal|42
argument_list|)
expr_stmt|;
operator|++
name|runCount
expr_stmt|;
block|}
DECL|function|~SingletonObject
name|~
name|SingletonObject
parameter_list|()
block|{ }
DECL|member|val
name|QBasicAtomicInt
name|val
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|IncrementThread
class|class
name|IncrementThread
super|:
specifier|public
name|QThread
block|{
public|public:
DECL|member|runCount
specifier|static
name|QBasicAtomicInt
name|runCount
decl_stmt|;
DECL|member|singleton
specifier|static
name|QSingleton
argument_list|<
name|SingletonObject
argument_list|>
name|singleton
decl_stmt|;
DECL|member|sem1
DECL|member|sem2
name|QSemaphore
modifier|&
name|sem1
decl_stmt|,
modifier|&
name|sem2
decl_stmt|;
DECL|member|var
name|int
modifier|&
name|var
decl_stmt|;
DECL|function|IncrementThread
name|IncrementThread
parameter_list|(
name|QSemaphore
modifier|*
name|psem1
parameter_list|,
name|QSemaphore
modifier|*
name|psem2
parameter_list|,
name|int
modifier|*
name|pvar
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|sem1
argument_list|(
operator|*
name|psem1
argument_list|)
member_init_list|,
name|sem2
argument_list|(
operator|*
name|psem2
argument_list|)
member_init_list|,
name|var
argument_list|(
operator|*
name|pvar
argument_list|)
block|{
name|start
argument_list|()
expr_stmt|;
block|}
DECL|function|~IncrementThread
name|~
name|IncrementThread
parameter_list|()
block|{
name|wait
argument_list|()
expr_stmt|;
block|}
protected|protected:
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|sem2
operator|.
name|release
argument_list|()
expr_stmt|;
name|sem1
operator|.
name|acquire
argument_list|()
expr_stmt|;
comment|// synchronize
name|Q_ONCE
block|{
operator|++
name|var
expr_stmt|;
block|}
name|runCount
operator|.
name|ref
argument_list|()
expr_stmt|;
name|singleton
operator|->
name|val
operator|.
name|ref
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_decl_stmt
DECL|member|runCount
name|int
name|SingletonObject
operator|::
name|runCount
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|runCount
name|QBasicAtomicInt
name|IncrementThread
operator|::
name|runCount
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|singleton
name|QSingleton
argument_list|<
name|SingletonObject
argument_list|>
name|IncrementThread
operator|::
name|singleton
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|sameThread_data
name|void
name|tst_QThreadOnce
operator|::
name|sameThread_data
parameter_list|()
block|{
name|SingletonObject
operator|::
name|runCount
operator|=
literal|0
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"expectedValue"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"first"
argument_list|)
operator|<<
literal|42
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"second"
argument_list|)
operator|<<
literal|43
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sameThread
name|void
name|tst_QThreadOnce
operator|::
name|sameThread
parameter_list|()
block|{
specifier|static
name|int
name|controlVariable
init|=
literal|0
decl_stmt|;
name|Q_ONCE
block|{
name|QCOMPARE
argument_list|(
name|controlVariable
argument_list|,
literal|0
argument_list|)
expr_stmt|;
operator|++
name|controlVariable
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|controlVariable
argument_list|,
literal|1
argument_list|)
expr_stmt|;
specifier|static
name|QSingleton
argument_list|<
name|SingletonObject
argument_list|>
name|s
decl_stmt|;
name|QTEST
argument_list|(
operator|(
name|int
operator|)
name|s
operator|->
name|val
operator|.
name|load
argument_list|()
argument_list|,
literal|"expectedValue"
argument_list|)
expr_stmt|;
name|s
operator|->
name|val
operator|.
name|ref
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|SingletonObject
operator|::
name|runCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|multipleThreads
name|void
name|tst_QThreadOnce
operator|::
name|multipleThreads
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
specifier|const
name|int
name|NumberOfThreads
init|=
literal|20
decl_stmt|;
else|#
directive|else
specifier|const
name|int
name|NumberOfThreads
init|=
literal|100
decl_stmt|;
endif|#
directive|endif
name|int
name|controlVariable
init|=
literal|0
decl_stmt|;
name|QSemaphore
name|sem1
decl_stmt|,
name|sem2
argument_list|(
name|NumberOfThreads
argument_list|)
decl_stmt|;
name|QObject
modifier|*
name|parent
init|=
operator|new
name|QObject
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
name|NumberOfThreads
condition|;
operator|++
name|i
control|)
operator|new
name|IncrementThread
argument_list|(
operator|&
name|sem1
argument_list|,
operator|&
name|sem2
argument_list|,
operator|&
name|controlVariable
argument_list|,
name|parent
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|controlVariable
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// nothing must have set them yet
name|SingletonObject
operator|::
name|runCount
operator|=
literal|0
expr_stmt|;
name|IncrementThread
operator|::
name|runCount
operator|.
name|store
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// wait for all of them to be ready
name|sem2
operator|.
name|acquire
argument_list|(
name|NumberOfThreads
argument_list|)
expr_stmt|;
comment|// unleash the threads
name|sem1
operator|.
name|release
argument_list|(
name|NumberOfThreads
argument_list|)
expr_stmt|;
comment|// wait for all of them to terminate:
operator|delete
name|parent
expr_stmt|;
name|QCOMPARE
argument_list|(
name|controlVariable
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|int
operator|)
name|IncrementThread
operator|::
name|runCount
operator|.
name|load
argument_list|()
argument_list|,
name|NumberOfThreads
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|SingletonObject
operator|::
name|runCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nesting
name|void
name|tst_QThreadOnce
operator|::
name|nesting
parameter_list|()
block|{
name|int
name|variable
init|=
literal|0
decl_stmt|;
name|Q_ONCE
block|{
name|Q_ONCE
block|{
operator|++
name|variable
expr_stmt|;
block|}
block|}
name|QVERIFY
argument_list|(
name|variable
operator|==
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reentrant
specifier|static
name|void
name|reentrant
parameter_list|(
name|int
name|control
parameter_list|,
name|int
modifier|&
name|counter
parameter_list|)
block|{
name|Q_ONCE
block|{
if|if
condition|(
name|counter
condition|)
name|reentrant
argument_list|(
operator|--
name|control
argument_list|,
name|counter
argument_list|)
expr_stmt|;
operator|++
name|counter
expr_stmt|;
block|}
specifier|static
name|QSingleton
argument_list|<
name|SingletonObject
argument_list|>
name|s
decl_stmt|;
name|s
operator|->
name|val
operator|.
name|ref
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reentering
name|void
name|tst_QThreadOnce
operator|::
name|reentering
parameter_list|()
block|{
specifier|const
name|int
name|WantedRecursions
init|=
literal|5
decl_stmt|;
name|int
name|count
init|=
literal|0
decl_stmt|;
name|SingletonObject
operator|::
name|runCount
operator|=
literal|0
expr_stmt|;
name|reentrant
argument_list|(
name|WantedRecursions
argument_list|,
name|count
argument_list|)
expr_stmt|;
comment|// reentrancy is undefined behavior:
name|QVERIFY
argument_list|(
name|count
operator|==
literal|1
operator|||
name|count
operator|==
name|WantedRecursions
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|SingletonObject
operator|::
name|runCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_EXCEPTIONS
argument_list|)
end_if
begin_function
DECL|function|exception_helper
specifier|static
name|void
name|exception_helper
parameter_list|(
name|int
modifier|&
name|val
parameter_list|)
block|{
name|Q_ONCE
block|{
if|if
condition|(
name|val
operator|++
operator|==
literal|0
condition|)
throw|throw
literal|0
throw|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
end_ifndef
begin_function
DECL|function|exception
name|void
name|tst_QThreadOnce
operator|::
name|exception
parameter_list|()
block|{
name|int
name|count
init|=
literal|0
decl_stmt|;
try|try
block|{
name|exception_helper
argument_list|(
name|count
argument_list|)
expr_stmt|;
block|}
catch|catch
parameter_list|(
modifier|...
parameter_list|)
block|{
comment|// nothing
block|}
name|QCOMPARE
argument_list|(
name|count
argument_list|,
literal|1
argument_list|)
expr_stmt|;
try|try
block|{
name|exception_helper
argument_list|(
name|count
argument_list|)
expr_stmt|;
block|}
catch|catch
parameter_list|(
modifier|...
parameter_list|)
block|{
name|QVERIFY2
argument_list|(
literal|false
argument_list|,
literal|"Exception shouldn't have been thrown..."
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|count
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QThreadOnce
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qthreadonce.moc"
end_include
end_unit
