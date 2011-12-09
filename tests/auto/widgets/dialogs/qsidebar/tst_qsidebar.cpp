begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/private/qsidebar_p.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/private/qfilesystemmodel_p.h>
end_include
begin_class
DECL|class|tst_QSidebar
class|class
name|tst_QSidebar
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QSidebar
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QSidebar
parameter_list|()
destructor_decl|;
public|public
name|Q_SLOTS
public|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|setUrls
parameter_list|()
function_decl|;
name|void
name|selectUrls
parameter_list|()
function_decl|;
name|void
name|addUrls
parameter_list|()
function_decl|;
name|void
name|goToUrl
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QSidebar
name|tst_QSidebar
operator|::
name|tst_QSidebar
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QSidebar
name|tst_QSidebar
operator|::
name|~
name|tst_QSidebar
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|init
name|void
name|tst_QSidebar
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QSidebar
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|setUrls
name|void
name|tst_QSidebar
operator|::
name|setUrls
parameter_list|()
block|{
name|QList
argument_list|<
name|QUrl
argument_list|>
name|urls
decl_stmt|;
name|QFileSystemModel
name|fsmodel
decl_stmt|;
name|QSidebar
name|qsidebar
decl_stmt|;
name|qsidebar
operator|.
name|setModelAndUrls
argument_list|(
operator|&
name|fsmodel
argument_list|,
name|urls
argument_list|)
expr_stmt|;
name|QAbstractItemModel
modifier|*
name|model
init|=
name|qsidebar
operator|.
name|model
argument_list|()
decl_stmt|;
name|urls
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|QDir
operator|::
name|rootPath
argument_list|()
argument_list|)
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|QDir
operator|::
name|temp
argument_list|()
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|->
name|rowCount
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|setUrls
argument_list|(
name|urls
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qsidebar
operator|.
name|urls
argument_list|()
argument_list|,
name|urls
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|->
name|rowCount
argument_list|()
argument_list|,
name|urls
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|setUrls
argument_list|(
name|urls
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|->
name|rowCount
argument_list|()
argument_list|,
name|urls
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectUrls
name|void
name|tst_QSidebar
operator|::
name|selectUrls
parameter_list|()
block|{
name|QList
argument_list|<
name|QUrl
argument_list|>
name|urls
decl_stmt|;
name|urls
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|QDir
operator|::
name|rootPath
argument_list|()
argument_list|)
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|QDir
operator|::
name|temp
argument_list|()
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
name|QFileSystemModel
name|fsmodel
decl_stmt|;
name|QSidebar
name|qsidebar
decl_stmt|;
name|qsidebar
operator|.
name|setModelAndUrls
argument_list|(
operator|&
name|fsmodel
argument_list|,
name|urls
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|qsidebar
argument_list|,
name|SIGNAL
argument_list|(
name|goToUrl
argument_list|(
specifier|const
name|QUrl
operator|&
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|qsidebar
operator|.
name|selectUrl
argument_list|(
name|urls
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addUrls
name|void
name|tst_QSidebar
operator|::
name|addUrls
parameter_list|()
block|{
name|QList
argument_list|<
name|QUrl
argument_list|>
name|emptyUrls
decl_stmt|;
name|QFileSystemModel
name|fsmodel
decl_stmt|;
name|QSidebar
name|qsidebar
decl_stmt|;
name|qsidebar
operator|.
name|setModelAndUrls
argument_list|(
operator|&
name|fsmodel
argument_list|,
name|emptyUrls
argument_list|)
expr_stmt|;
name|QAbstractItemModel
modifier|*
name|model
init|=
name|qsidebar
operator|.
name|model
argument_list|()
decl_stmt|;
name|QDir
name|testDir
init|=
name|QDir
operator|::
name|home
argument_list|()
decl_stmt|;
comment|// default
name|QCOMPARE
argument_list|(
name|model
operator|->
name|rowCount
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QUrl
argument_list|>
name|urls
decl_stmt|;
name|urls
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|QDir
operator|::
name|rootPath
argument_list|()
argument_list|)
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|QDir
operator|::
name|temp
argument_list|()
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
comment|// test< 0
name|qsidebar
operator|.
name|addUrls
argument_list|(
name|urls
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|->
name|rowCount
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// test = 0
name|qsidebar
operator|.
name|setUrls
argument_list|(
name|emptyUrls
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|addUrls
argument_list|(
name|urls
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|->
name|rowCount
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// test> 0
name|qsidebar
operator|.
name|setUrls
argument_list|(
name|emptyUrls
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|addUrls
argument_list|(
name|urls
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|->
name|rowCount
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// test inserting with already existing rows
name|QList
argument_list|<
name|QUrl
argument_list|>
name|moreUrls
decl_stmt|;
name|moreUrls
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|testDir
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|addUrls
argument_list|(
name|moreUrls
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|->
name|rowCount
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// make sure invalid urls are still added
name|QList
argument_list|<
name|QUrl
argument_list|>
name|badUrls
decl_stmt|;
name|badUrls
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|testDir
operator|.
name|absolutePath
argument_list|()
operator|+
literal|"/I used to exist"
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|addUrls
argument_list|(
name|badUrls
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|->
name|rowCount
argument_list|()
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// check that every item has text and an icon including the above invalid one
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|model
operator|->
name|rowCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QVERIFY
argument_list|(
operator|!
name|model
operator|->
name|index
argument_list|(
name|i
argument_list|,
literal|0
argument_list|)
operator|.
name|data
argument_list|()
operator|.
name|toString
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QIcon
name|icon
init|=
name|qvariant_cast
argument_list|<
name|QIcon
argument_list|>
argument_list|(
name|model
operator|->
name|index
argument_list|(
name|i
argument_list|,
literal|0
argument_list|)
operator|.
name|data
argument_list|(
name|Qt
operator|::
name|DecorationRole
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|icon
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// test moving up the list
name|qsidebar
operator|.
name|setUrls
argument_list|(
name|emptyUrls
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|addUrls
argument_list|(
name|urls
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|addUrls
argument_list|(
name|moreUrls
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|->
name|rowCount
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|addUrls
argument_list|(
name|moreUrls
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qsidebar
operator|.
name|urls
argument_list|()
index|[
literal|1
index|]
argument_list|,
name|moreUrls
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|// test appending with -1
name|qsidebar
operator|.
name|setUrls
argument_list|(
name|emptyUrls
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|addUrls
argument_list|(
name|urls
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|addUrls
argument_list|(
name|moreUrls
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qsidebar
operator|.
name|urls
argument_list|()
index|[
literal|0
index|]
argument_list|,
name|urls
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QUrl
argument_list|>
name|doubleUrls
decl_stmt|;
comment|//tow exact same paths, we have only one entry
name|doubleUrls
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|testDir
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
name|doubleUrls
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|testDir
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|setUrls
argument_list|(
name|emptyUrls
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|addUrls
argument_list|(
name|doubleUrls
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qsidebar
operator|.
name|urls
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// Two paths that are effectively pointing to the same location
name|doubleUrls
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|testDir
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
name|doubleUrls
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|testDir
operator|.
name|absolutePath
argument_list|()
operator|+
literal|"/."
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|setUrls
argument_list|(
name|emptyUrls
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|addUrls
argument_list|(
name|doubleUrls
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qsidebar
operator|.
name|urls
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
comment|//Windows is case insensitive so no duplicate entries in that case
name|doubleUrls
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|testDir
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
name|doubleUrls
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|testDir
operator|.
name|absolutePath
argument_list|()
operator|.
name|toUpper
argument_list|()
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|setUrls
argument_list|(
name|emptyUrls
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|addUrls
argument_list|(
name|doubleUrls
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qsidebar
operator|.
name|urls
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|#
directive|else
comment|//Two different paths we should have two entries
name|doubleUrls
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|testDir
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
name|doubleUrls
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|testDir
operator|.
name|absolutePath
argument_list|()
operator|.
name|toUpper
argument_list|()
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|setUrls
argument_list|(
name|emptyUrls
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|addUrls
argument_list|(
name|doubleUrls
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qsidebar
operator|.
name|urls
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|goToUrl
name|void
name|tst_QSidebar
operator|::
name|goToUrl
parameter_list|()
block|{
name|QList
argument_list|<
name|QUrl
argument_list|>
name|urls
decl_stmt|;
name|urls
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|QDir
operator|::
name|rootPath
argument_list|()
argument_list|)
operator|<<
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|QDir
operator|::
name|temp
argument_list|()
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
name|QFileSystemModel
name|fsmodel
decl_stmt|;
name|QSidebar
name|qsidebar
decl_stmt|;
name|qsidebar
operator|.
name|setModelAndUrls
argument_list|(
operator|&
name|fsmodel
argument_list|,
name|urls
argument_list|)
expr_stmt|;
name|qsidebar
operator|.
name|show
argument_list|()
expr_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|qsidebar
argument_list|,
name|SIGNAL
argument_list|(
name|goToUrl
argument_list|(
specifier|const
name|QUrl
operator|&
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|mousePress
argument_list|(
name|qsidebar
operator|.
name|viewport
argument_list|()
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
literal|0
argument_list|,
name|qsidebar
operator|.
name|visualRect
argument_list|(
name|qsidebar
operator|.
name|model
argument_list|()
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|spy
operator|.
name|value
argument_list|(
literal|0
argument_list|)
operator|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toUrl
argument_list|()
argument_list|,
name|urls
operator|.
name|first
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSidebar
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsidebar.moc"
end_include
end_unit
