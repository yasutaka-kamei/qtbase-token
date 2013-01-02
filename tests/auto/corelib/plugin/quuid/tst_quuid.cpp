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
file|<quuid.h>
end_include
begin_class
DECL|class|tst_QUuid
class|class
name|tst_QUuid
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|fromChar
parameter_list|()
function_decl|;
name|void
name|toString
parameter_list|()
function_decl|;
name|void
name|fromString
parameter_list|()
function_decl|;
name|void
name|toByteArray
parameter_list|()
function_decl|;
name|void
name|fromByteArray
parameter_list|()
function_decl|;
name|void
name|toRfc4122
parameter_list|()
function_decl|;
name|void
name|fromRfc4122
parameter_list|()
function_decl|;
name|void
name|createUuidV3OrV5
parameter_list|()
function_decl|;
name|void
name|check_QDataStream
parameter_list|()
function_decl|;
name|void
name|isNull
parameter_list|()
function_decl|;
name|void
name|equal
parameter_list|()
function_decl|;
name|void
name|notEqual
parameter_list|()
function_decl|;
comment|// Only in Qt> 3.2.x
name|void
name|generate
parameter_list|()
function_decl|;
name|void
name|less
parameter_list|()
function_decl|;
name|void
name|more
parameter_list|()
function_decl|;
name|void
name|variants
parameter_list|()
function_decl|;
name|void
name|versions
parameter_list|()
function_decl|;
name|void
name|threadUniqueness
parameter_list|()
function_decl|;
name|void
name|processUniqueness
parameter_list|()
function_decl|;
name|void
name|hash
parameter_list|()
function_decl|;
name|void
name|qvariant
parameter_list|()
function_decl|;
name|void
name|qvariant_conversion
parameter_list|()
function_decl|;
public|public:
comment|// Variables
DECL|member|uuidNS
name|QUuid
name|uuidNS
decl_stmt|;
DECL|member|uuidA
name|QUuid
name|uuidA
decl_stmt|;
DECL|member|uuidB
name|QUuid
name|uuidB
decl_stmt|;
DECL|member|uuidC
name|QUuid
name|uuidC
decl_stmt|;
DECL|member|uuidD
name|QUuid
name|uuidD
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_QUuid
operator|::
name|initTestCase
parameter_list|()
block|{
comment|//It's NameSpace_DNS in RFC4122
comment|//"{6ba7b810-9dad-11d1-80b4-00c04fd430c8}";
name|uuidNS
operator|=
name|QUuid
argument_list|(
literal|0x6ba7b810
argument_list|,
literal|0x9dad
argument_list|,
literal|0x11d1
argument_list|,
literal|0x80
argument_list|,
literal|0xb4
argument_list|,
literal|0x00
argument_list|,
literal|0xc0
argument_list|,
literal|0x4f
argument_list|,
literal|0xd4
argument_list|,
literal|0x30
argument_list|,
literal|0xc8
argument_list|)
expr_stmt|;
comment|//"{fc69b59e-cc34-4436-a43c-ee95d128b8c5}";
name|uuidA
operator|=
name|QUuid
argument_list|(
literal|0xfc69b59e
argument_list|,
literal|0xcc34
argument_list|,
literal|0x4436
argument_list|,
literal|0xa4
argument_list|,
literal|0x3c
argument_list|,
literal|0xee
argument_list|,
literal|0x95
argument_list|,
literal|0xd1
argument_list|,
literal|0x28
argument_list|,
literal|0xb8
argument_list|,
literal|0xc5
argument_list|)
expr_stmt|;
comment|//"{1ab6e93a-b1cb-4a87-ba47-ec7e99039a7b}";
name|uuidB
operator|=
name|QUuid
argument_list|(
literal|0x1ab6e93a
argument_list|,
literal|0xb1cb
argument_list|,
literal|0x4a87
argument_list|,
literal|0xba
argument_list|,
literal|0x47
argument_list|,
literal|0xec
argument_list|,
literal|0x7e
argument_list|,
literal|0x99
argument_list|,
literal|0x03
argument_list|,
literal|0x9a
argument_list|,
literal|0x7b
argument_list|)
expr_stmt|;
comment|// chdir to the directory containing our testdata, then refer to it with relative paths
name|QString
name|testdata_dir
init|=
name|QFileInfo
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"testProcessUniqueness"
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
name|testdata_dir
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
literal|"Could not chdir to "
operator|+
name|testdata_dir
argument_list|)
argument_list|)
expr_stmt|;
comment|//"{3d813cbb-47fb-32ba-91df-831e1593ac29}"; http://www.rfc-editor.org/errata_search.php?rfc=4122&eid=1352
name|uuidC
operator|=
name|QUuid
argument_list|(
literal|0x3d813cbb
argument_list|,
literal|0x47fb
argument_list|,
literal|0x32ba
argument_list|,
literal|0x91
argument_list|,
literal|0xdf
argument_list|,
literal|0x83
argument_list|,
literal|0x1e
argument_list|,
literal|0x15
argument_list|,
literal|0x93
argument_list|,
literal|0xac
argument_list|,
literal|0x29
argument_list|)
expr_stmt|;
comment|//"{21f7f8de-8051-5b89-8680-0195ef798b6a}";
name|uuidD
operator|=
name|QUuid
argument_list|(
literal|0x21f7f8de
argument_list|,
literal|0x8051
argument_list|,
literal|0x5b89
argument_list|,
literal|0x86
argument_list|,
literal|0x80
argument_list|,
literal|0x01
argument_list|,
literal|0x95
argument_list|,
literal|0xef
argument_list|,
literal|0x79
argument_list|,
literal|0x8b
argument_list|,
literal|0x6a
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fromChar
name|void
name|tst_QUuid
operator|::
name|fromChar
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|uuidA
argument_list|,
name|QUuid
argument_list|(
literal|"{fc69b59e-cc34-4436-a43c-ee95d128b8c5}"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidA
argument_list|,
name|QUuid
argument_list|(
literal|"fc69b59e-cc34-4436-a43c-ee95d128b8c5}"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidA
argument_list|,
name|QUuid
argument_list|(
literal|"{fc69b59e-cc34-4436-a43c-ee95d128b8c5"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidA
argument_list|,
name|QUuid
argument_list|(
literal|"fc69b59e-cc34-4436-a43c-ee95d128b8c5"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QUuid
argument_list|()
argument_list|,
name|QUuid
argument_list|(
literal|"{fc69b59e-cc34-4436-a43c-ee95d128b8c"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QUuid
argument_list|()
argument_list|,
name|QUuid
argument_list|(
literal|"{fc69b59e-cc34"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QUuid
argument_list|()
argument_list|,
name|QUuid
argument_list|(
literal|"fc69b59e-cc34-"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QUuid
argument_list|()
argument_list|,
name|QUuid
argument_list|(
literal|"fc69b59e-cc34"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QUuid
argument_list|()
argument_list|,
name|QUuid
argument_list|(
literal|"cc34"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QUuid
argument_list|()
argument_list|,
name|QUuid
argument_list|(
name|NULL
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidB
argument_list|,
name|QUuid
argument_list|(
name|QString
argument_list|(
literal|"{1ab6e93a-b1cb-4a87-ba47-ec7e99039a7b}"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toString
name|void
name|tst_QUuid
operator|::
name|toString
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|uuidA
operator|.
name|toString
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"{fc69b59e-cc34-4436-a43c-ee95d128b8c5}"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidB
operator|.
name|toString
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"{1ab6e93a-b1cb-4a87-ba47-ec7e99039a7b}"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fromString
name|void
name|tst_QUuid
operator|::
name|fromString
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|uuidA
argument_list|,
name|QUuid
argument_list|(
name|QString
argument_list|(
literal|"{fc69b59e-cc34-4436-a43c-ee95d128b8c5}"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidA
argument_list|,
name|QUuid
argument_list|(
name|QString
argument_list|(
literal|"fc69b59e-cc34-4436-a43c-ee95d128b8c5}"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidA
argument_list|,
name|QUuid
argument_list|(
name|QString
argument_list|(
literal|"{fc69b59e-cc34-4436-a43c-ee95d128b8c5"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidA
argument_list|,
name|QUuid
argument_list|(
name|QString
argument_list|(
literal|"fc69b59e-cc34-4436-a43c-ee95d128b8c5"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QUuid
argument_list|()
argument_list|,
name|QUuid
argument_list|(
name|QString
argument_list|(
literal|"{fc69b59e-cc34-4436-a43c-ee95d128b8c"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidB
argument_list|,
name|QUuid
argument_list|(
name|QString
argument_list|(
literal|"{1ab6e93a-b1cb-4a87-ba47-ec7e99039a7b}"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toByteArray
name|void
name|tst_QUuid
operator|::
name|toByteArray
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|uuidA
operator|.
name|toByteArray
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"{fc69b59e-cc34-4436-a43c-ee95d128b8c5}"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidB
operator|.
name|toByteArray
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"{1ab6e93a-b1cb-4a87-ba47-ec7e99039a7b}"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fromByteArray
name|void
name|tst_QUuid
operator|::
name|fromByteArray
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|uuidA
argument_list|,
name|QUuid
argument_list|(
name|QByteArray
argument_list|(
literal|"{fc69b59e-cc34-4436-a43c-ee95d128b8c5}"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidA
argument_list|,
name|QUuid
argument_list|(
name|QByteArray
argument_list|(
literal|"fc69b59e-cc34-4436-a43c-ee95d128b8c5}"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidA
argument_list|,
name|QUuid
argument_list|(
name|QByteArray
argument_list|(
literal|"{fc69b59e-cc34-4436-a43c-ee95d128b8c5"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidA
argument_list|,
name|QUuid
argument_list|(
name|QByteArray
argument_list|(
literal|"fc69b59e-cc34-4436-a43c-ee95d128b8c5"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QUuid
argument_list|()
argument_list|,
name|QUuid
argument_list|(
name|QByteArray
argument_list|(
literal|"{fc69b59e-cc34-4436-a43c-ee95d128b8c"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidB
argument_list|,
name|QUuid
argument_list|(
name|QByteArray
argument_list|(
literal|"{1ab6e93a-b1cb-4a87-ba47-ec7e99039a7b}"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toRfc4122
name|void
name|tst_QUuid
operator|::
name|toRfc4122
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|uuidA
operator|.
name|toRfc4122
argument_list|()
argument_list|,
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"fc69b59ecc344436a43cee95d128b8c5"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidB
operator|.
name|toRfc4122
argument_list|()
argument_list|,
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"1ab6e93ab1cb4a87ba47ec7e99039a7b"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fromRfc4122
name|void
name|tst_QUuid
operator|::
name|fromRfc4122
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|uuidA
argument_list|,
name|QUuid
operator|::
name|fromRfc4122
argument_list|(
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"fc69b59ecc344436a43cee95d128b8c5"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidB
argument_list|,
name|QUuid
operator|::
name|fromRfc4122
argument_list|(
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"1ab6e93ab1cb4a87ba47ec7e99039a7b"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createUuidV3OrV5
name|void
name|tst_QUuid
operator|::
name|createUuidV3OrV5
parameter_list|()
block|{
comment|//"www.widgets.com" is also from RFC4122
name|QCOMPARE
argument_list|(
name|uuidC
argument_list|,
name|QUuid
operator|::
name|createUuidV3
argument_list|(
name|uuidNS
argument_list|,
name|QByteArray
argument_list|(
literal|"www.widgets.com"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidC
argument_list|,
name|QUuid
operator|::
name|createUuidV3
argument_list|(
name|uuidNS
argument_list|,
name|QString
argument_list|(
literal|"www.widgets.com"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidD
argument_list|,
name|QUuid
operator|::
name|createUuidV5
argument_list|(
name|uuidNS
argument_list|,
name|QByteArray
argument_list|(
literal|"www.widgets.com"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidD
argument_list|,
name|QUuid
operator|::
name|createUuidV5
argument_list|(
name|uuidNS
argument_list|,
name|QString
argument_list|(
literal|"www.widgets.com"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|check_QDataStream
name|void
name|tst_QUuid
operator|::
name|check_QDataStream
parameter_list|()
block|{
name|QUuid
name|tmp
decl_stmt|;
name|QByteArray
name|ar
decl_stmt|;
block|{
name|QDataStream
name|out
argument_list|(
operator|&
name|ar
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
name|out
operator|.
name|setByteOrder
argument_list|(
name|QDataStream
operator|::
name|BigEndian
argument_list|)
expr_stmt|;
name|out
operator|<<
name|uuidA
expr_stmt|;
block|}
block|{
name|QDataStream
name|in
argument_list|(
operator|&
name|ar
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|in
operator|.
name|setByteOrder
argument_list|(
name|QDataStream
operator|::
name|BigEndian
argument_list|)
expr_stmt|;
name|in
operator|>>
name|tmp
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidA
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
block|}
block|{
name|QDataStream
name|out
argument_list|(
operator|&
name|ar
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
name|out
operator|.
name|setByteOrder
argument_list|(
name|QDataStream
operator|::
name|LittleEndian
argument_list|)
expr_stmt|;
name|out
operator|<<
name|uuidA
expr_stmt|;
block|}
block|{
name|QDataStream
name|in
argument_list|(
operator|&
name|ar
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|in
operator|.
name|setByteOrder
argument_list|(
name|QDataStream
operator|::
name|LittleEndian
argument_list|)
expr_stmt|;
name|in
operator|>>
name|tmp
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuidA
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|isNull
name|void
name|tst_QUuid
operator|::
name|isNull
parameter_list|()
block|{
name|QVERIFY
argument_list|(
operator|!
name|uuidA
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QUuid
name|should_be_null_uuid
decl_stmt|;
name|QVERIFY
argument_list|(
name|should_be_null_uuid
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|equal
name|void
name|tst_QUuid
operator|::
name|equal
parameter_list|()
block|{
name|QVERIFY
argument_list|(
operator|!
operator|(
name|uuidA
operator|==
name|uuidB
operator|)
argument_list|)
expr_stmt|;
name|QUuid
name|copy
argument_list|(
name|uuidA
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|uuidA
operator|==
name|copy
argument_list|)
expr_stmt|;
name|QUuid
name|assigned
decl_stmt|;
name|assigned
operator|=
name|uuidA
expr_stmt|;
name|QVERIFY
argument_list|(
name|uuidA
operator|==
name|assigned
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|notEqual
name|void
name|tst_QUuid
operator|::
name|notEqual
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|uuidA
operator|!=
name|uuidB
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|generate
name|void
name|tst_QUuid
operator|::
name|generate
parameter_list|()
block|{
name|QUuid
name|shouldnt_be_null_uuidA
init|=
name|QUuid
operator|::
name|createUuid
argument_list|()
decl_stmt|;
name|QUuid
name|shouldnt_be_null_uuidB
init|=
name|QUuid
operator|::
name|createUuid
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|shouldnt_be_null_uuidA
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|shouldnt_be_null_uuidB
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|shouldnt_be_null_uuidA
operator|!=
name|shouldnt_be_null_uuidB
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|less
name|void
name|tst_QUuid
operator|::
name|less
parameter_list|()
block|{
name|QVERIFY
argument_list|(
operator|!
operator|(
name|uuidA
operator|<
name|uuidB
operator|)
argument_list|)
expr_stmt|;
name|QUuid
name|null_uuid
decl_stmt|;
name|QVERIFY
argument_list|(
name|null_uuid
operator|<
name|uuidA
argument_list|)
expr_stmt|;
comment|// Null uuid is always less than a valid one
block|}
end_function
begin_function
DECL|function|more
name|void
name|tst_QUuid
operator|::
name|more
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|uuidA
operator|>
name|uuidB
argument_list|)
expr_stmt|;
name|QUuid
name|null_uuid
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|null_uuid
operator|>
name|uuidA
operator|)
argument_list|)
expr_stmt|;
comment|// Null uuid is always less than a valid one
block|}
end_function
begin_function
DECL|function|variants
name|void
name|tst_QUuid
operator|::
name|variants
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|uuidA
operator|.
name|variant
argument_list|()
operator|==
name|QUuid
operator|::
name|DCE
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|uuidB
operator|.
name|variant
argument_list|()
operator|==
name|QUuid
operator|::
name|DCE
argument_list|)
expr_stmt|;
name|QUuid
name|NCS
init|=
literal|"{3a2f883c-4000-000d-0000-00fb40000000}"
decl_stmt|;
name|QVERIFY
argument_list|(
name|NCS
operator|.
name|variant
argument_list|()
operator|==
name|QUuid
operator|::
name|NCS
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|versions
name|void
name|tst_QUuid
operator|::
name|versions
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|uuidA
operator|.
name|version
argument_list|()
operator|==
name|QUuid
operator|::
name|Random
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|uuidB
operator|.
name|version
argument_list|()
operator|==
name|QUuid
operator|::
name|Random
argument_list|)
expr_stmt|;
name|QUuid
name|DCE_time
init|=
literal|"{406c45a0-3b7e-11d0-80a3-0000c08810a7}"
decl_stmt|;
name|QVERIFY
argument_list|(
name|DCE_time
operator|.
name|version
argument_list|()
operator|==
name|QUuid
operator|::
name|Time
argument_list|)
expr_stmt|;
name|QUuid
name|NCS
init|=
literal|"{3a2f883c-4000-000d-0000-00fb40000000}"
decl_stmt|;
name|QVERIFY
argument_list|(
name|NCS
operator|.
name|version
argument_list|()
operator|==
name|QUuid
operator|::
name|VerUnknown
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|UuidThread
class|class
name|UuidThread
super|:
specifier|public
name|QThread
block|{
public|public:
DECL|member|uuid
name|QUuid
name|uuid
decl_stmt|;
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|uuid
operator|=
name|QUuid
operator|::
name|createUuid
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|threadUniqueness
name|void
name|tst_QUuid
operator|::
name|threadUniqueness
parameter_list|()
block|{
name|QVector
argument_list|<
name|UuidThread
modifier|*
argument_list|>
name|threads
argument_list|(
name|qMax
argument_list|(
literal|2
argument_list|,
name|QThread
operator|::
name|idealThreadCount
argument_list|()
argument_list|)
argument_list|)
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
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|threads
index|[
name|i
index|]
operator|=
operator|new
name|UuidThread
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|threads
index|[
name|i
index|]
operator|->
name|start
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|QVERIFY
argument_list|(
name|threads
index|[
name|i
index|]
operator|->
name|wait
argument_list|(
literal|1000
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|QVERIFY
argument_list|(
name|threads
index|[
literal|0
index|]
operator|->
name|uuid
operator|!=
name|threads
index|[
name|i
index|]
operator|->
name|uuid
argument_list|)
expr_stmt|;
name|qDeleteAll
argument_list|(
name|threads
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|processUniqueness
name|void
name|tst_QUuid
operator|::
name|processUniqueness
parameter_list|()
block|{
name|QProcess
name|process
decl_stmt|;
name|QString
name|processOneOutput
decl_stmt|;
name|QString
name|processTwoOutput
decl_stmt|;
comment|// Start it once
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|process
operator|.
name|start
argument_list|(
literal|"testProcessUniqueness/testProcessUniqueness.app"
argument_list|)
expr_stmt|;
else|#
directive|else
name|process
operator|.
name|start
argument_list|(
literal|"testProcessUniqueness/testProcessUniqueness"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|process
operator|.
name|waitForFinished
argument_list|()
argument_list|)
expr_stmt|;
name|processOneOutput
operator|=
name|process
operator|.
name|readAllStandardOutput
argument_list|()
expr_stmt|;
comment|// Start it twice
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|process
operator|.
name|start
argument_list|(
literal|"testProcessUniqueness/testProcessUniqueness.app"
argument_list|)
expr_stmt|;
else|#
directive|else
name|process
operator|.
name|start
argument_list|(
literal|"testProcessUniqueness/testProcessUniqueness"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|process
operator|.
name|waitForFinished
argument_list|()
argument_list|)
expr_stmt|;
name|processTwoOutput
operator|=
name|process
operator|.
name|readAllStandardOutput
argument_list|()
expr_stmt|;
comment|// They should be *different*!
name|QVERIFY
argument_list|(
name|processOneOutput
operator|!=
name|processTwoOutput
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hash
name|void
name|tst_QUuid
operator|::
name|hash
parameter_list|()
block|{
name|uint
name|h
init|=
name|qHash
argument_list|(
name|uuidA
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|qHash
argument_list|(
name|uuidA
argument_list|)
argument_list|,
name|h
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qHash
argument_list|(
name|QUuid
argument_list|(
name|uuidA
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
argument_list|,
name|h
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qvariant
name|void
name|tst_QUuid
operator|::
name|qvariant
parameter_list|()
block|{
name|QUuid
name|uuid
init|=
name|QUuid
operator|::
name|createUuid
argument_list|()
decl_stmt|;
name|QVariant
name|v
init|=
name|QVariant
operator|::
name|fromValue
argument_list|(
name|uuid
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|v
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|v
operator|.
name|type
argument_list|()
argument_list|,
name|QVariant
operator|::
name|Uuid
argument_list|)
expr_stmt|;
name|QUuid
name|uuid2
init|=
name|v
operator|.
name|value
argument_list|<
name|QUuid
argument_list|>
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|uuid2
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|uuid
argument_list|,
name|uuid2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qvariant_conversion
name|void
name|tst_QUuid
operator|::
name|qvariant_conversion
parameter_list|()
block|{
name|QUuid
name|uuid
init|=
name|QUuid
operator|::
name|createUuid
argument_list|()
decl_stmt|;
name|QVariant
name|v
init|=
name|QVariant
operator|::
name|fromValue
argument_list|(
name|uuid
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|v
operator|.
name|canConvert
argument_list|<
name|QString
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|v
operator|.
name|toString
argument_list|()
argument_list|,
name|uuid
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|v
operator|.
name|value
argument_list|<
name|QString
argument_list|>
argument_list|()
argument_list|,
name|uuid
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|v
operator|.
name|canConvert
argument_list|<
name|int
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|v
operator|.
name|canConvert
argument_list|<
name|QStringList
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
comment|// try reverse conversion QString -> QUuid
name|QVariant
name|sv
init|=
name|QVariant
operator|::
name|fromValue
argument_list|(
name|uuid
operator|.
name|toString
argument_list|()
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|sv
operator|.
name|type
argument_list|()
argument_list|,
name|QVariant
operator|::
name|String
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sv
operator|.
name|canConvert
argument_list|<
name|QUuid
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sv
operator|.
name|value
argument_list|<
name|QUuid
argument_list|>
argument_list|()
argument_list|,
name|uuid
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QUuid
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_quuid.moc"
end_include
end_unit
