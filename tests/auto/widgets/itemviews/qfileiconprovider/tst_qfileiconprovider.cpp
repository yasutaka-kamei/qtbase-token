begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qfileiconprovider.h>
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_class
DECL|class|tst_QFileIconProvider
class|class
name|tst_QFileIconProvider
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
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
name|qfileiconprovider_data
parameter_list|()
function_decl|;
name|void
name|qfileiconprovider
parameter_list|()
function_decl|;
name|void
name|iconType_data
parameter_list|()
function_decl|;
name|void
name|iconType
parameter_list|()
function_decl|;
name|void
name|iconInfo_data
parameter_list|()
function_decl|;
name|void
name|iconInfo
parameter_list|()
function_decl|;
name|void
name|type_data
parameter_list|()
function_decl|;
name|void
name|type
parameter_list|()
function_decl|;
name|void
name|taskQTBUG_46755_QFileIconEngine_crash
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|// Subclass that exposes the protected functions.
end_comment
begin_class
DECL|class|SubQFileIconProvider
class|class
name|SubQFileIconProvider
super|:
specifier|public
name|QFileIconProvider
block|{
public|public:
block|}
class|;
end_class
begin_comment
comment|// This will be called before the first test function is executed.
end_comment
begin_comment
comment|// It is only called once.
end_comment
begin_function
DECL|function|initTestCase
name|void
name|tst_QFileIconProvider
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_comment
comment|// This will be called after the last test function is executed.
end_comment
begin_comment
comment|// It is only called once.
end_comment
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QFileIconProvider
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_comment
comment|// This will be called before each test function is executed.
end_comment
begin_function
DECL|function|init
name|void
name|tst_QFileIconProvider
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_comment
comment|// This will be called after every test function.
end_comment
begin_function
DECL|function|cleanup
name|void
name|tst_QFileIconProvider
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|qfileiconprovider_data
name|void
name|tst_QFileIconProvider
operator|::
name|qfileiconprovider_data
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|qfileiconprovider
name|void
name|tst_QFileIconProvider
operator|::
name|qfileiconprovider
parameter_list|()
block|{
comment|// don't crash
name|SubQFileIconProvider
name|provider
decl_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QFileIconProvider::IconType
argument_list|)
end_macro
begin_function
DECL|function|iconType_data
name|void
name|tst_QFileIconProvider
operator|::
name|iconType_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QFileIconProvider
operator|::
name|IconType
argument_list|>
argument_list|(
literal|"type"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"computer"
argument_list|)
operator|<<
name|QFileIconProvider
operator|::
name|Computer
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"desktop"
argument_list|)
operator|<<
name|QFileIconProvider
operator|::
name|Desktop
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"trashcan"
argument_list|)
operator|<<
name|QFileIconProvider
operator|::
name|Trashcan
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"network"
argument_list|)
operator|<<
name|QFileIconProvider
operator|::
name|Network
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"drive"
argument_list|)
operator|<<
name|QFileIconProvider
operator|::
name|Drive
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"folder"
argument_list|)
operator|<<
name|QFileIconProvider
operator|::
name|Folder
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"file"
argument_list|)
operator|<<
name|QFileIconProvider
operator|::
name|File
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QIcon icon(QFileIconProvider::IconType const& type) const
end_comment
begin_function
DECL|function|iconType
name|void
name|tst_QFileIconProvider
operator|::
name|iconType
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QFileIconProvider
operator|::
name|IconType
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|SubQFileIconProvider
name|provider
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|provider
operator|.
name|icon
argument_list|(
name|type
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|iconInfo_data
name|void
name|tst_QFileIconProvider
operator|::
name|iconInfo_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QFileInfo
argument_list|>
argument_list|(
literal|"info"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"setPath"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QFileInfo
argument_list|()
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"drive"
argument_list|)
operator|<<
name|QFileInfo
argument_list|(
name|QDir
operator|::
name|rootPath
argument_list|()
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"home"
argument_list|)
operator|<<
name|QFileInfo
argument_list|(
name|QDir
operator|::
name|homePath
argument_list|()
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"current"
argument_list|)
operator|<<
name|QFileInfo
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QIcon icon(QFileInfo const& info) const
end_comment
begin_function
DECL|function|iconInfo
name|void
name|tst_QFileIconProvider
operator|::
name|iconInfo
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QFileInfo
argument_list|,
name|info
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|setPath
argument_list|)
expr_stmt|;
if|if
condition|(
name|setPath
condition|)
name|QVERIFY
argument_list|(
name|info
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
name|SubQFileIconProvider
name|provider
decl_stmt|;
comment|// we should always get an icon
name|QVERIFY
argument_list|(
operator|!
name|provider
operator|.
name|icon
argument_list|(
name|info
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|type_data
name|void
name|tst_QFileIconProvider
operator|::
name|type_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QFileInfo
argument_list|>
argument_list|(
literal|"info"
argument_list|)
expr_stmt|;
comment|// Return value is _very_ system dependent, hard to test
comment|// QTest::addColumn<QString>("type");
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QFileInfo
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"drive"
argument_list|)
operator|<<
name|QFileInfo
argument_list|(
name|QDir
operator|::
name|rootPath
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"home"
argument_list|)
operator|<<
name|QFileInfo
argument_list|(
name|QDir
operator|::
name|homePath
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"current"
argument_list|)
operator|<<
name|QFileInfo
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"exe"
argument_list|)
operator|<<
name|QFileInfo
argument_list|(
name|QCoreApplication
operator|::
name|applicationFilePath
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QString type(QFileInfo const& info) const
end_comment
begin_function
DECL|function|type
name|void
name|tst_QFileIconProvider
operator|::
name|type
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QFileInfo
argument_list|,
name|info
argument_list|)
expr_stmt|;
name|SubQFileIconProvider
name|provider
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|provider
operator|.
name|type
argument_list|(
name|info
argument_list|)
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getIcon
specifier|static
name|QIcon
name|getIcon
parameter_list|()
block|{
name|QFileIconProvider
name|fip
decl_stmt|;
return|return
name|fip
operator|.
name|icon
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|taskQTBUG_46755_QFileIconEngine_crash
name|void
name|tst_QFileIconProvider
operator|::
name|taskQTBUG_46755_QFileIconEngine_crash
parameter_list|()
block|{
specifier|const
name|QIcon
modifier|&
name|icon
init|=
name|getIcon
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QSize
modifier|&
name|size
decl|,
name|icon
operator|.
name|availableSizes
argument_list|()
control|)
name|icon
operator|.
name|pixmap
argument_list|(
name|size
argument_list|)
expr_stmt|;
comment|// No crash, all good.
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QFileIconProvider
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qfileiconprovider.moc"
end_include
end_unit
