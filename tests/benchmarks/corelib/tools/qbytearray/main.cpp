begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QIODevice>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_class
DECL|class|tst_qbytearray
class|class
name|tst_qbytearray
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
DECL|member|sourcecode
name|QByteArray
name|sourcecode
decl_stmt|;
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|append
parameter_list|()
function_decl|;
name|void
name|append_data
parameter_list|()
function_decl|;
name|void
name|latin1Uppercasing_qt54
parameter_list|()
function_decl|;
name|void
name|latin1Uppercasing_xlate
parameter_list|()
function_decl|;
name|void
name|latin1Uppercasing_xlate_checked
parameter_list|()
function_decl|;
name|void
name|latin1Uppercasing_category
parameter_list|()
function_decl|;
name|void
name|latin1Uppercasing_bitcheck
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_qbytearray
operator|::
name|initTestCase
parameter_list|()
block|{
name|QFile
name|self
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"main.cpp"
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|self
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|sourcecode
operator|=
name|self
operator|.
name|readAll
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|append_data
name|void
name|tst_qbytearray
operator|::
name|append_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1"
argument_list|)
operator|<<
name|int
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10"
argument_list|)
operator|<<
name|int
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"100"
argument_list|)
operator|<<
name|int
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1000"
argument_list|)
operator|<<
name|int
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10000"
argument_list|)
operator|<<
name|int
argument_list|(
literal|10000
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"100000"
argument_list|)
operator|<<
name|int
argument_list|(
literal|100000
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1000000"
argument_list|)
operator|<<
name|int
argument_list|(
literal|1000000
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10000000"
argument_list|)
operator|<<
name|int
argument_list|(
literal|10000000
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"100000000"
argument_list|)
operator|<<
name|int
argument_list|(
literal|100000000
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|append
name|void
name|tst_qbytearray
operator|::
name|append
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QByteArray
name|ba
decl_stmt|;
name|QBENCHMARK
block|{
name|QByteArray
name|ba2
argument_list|(
name|size
argument_list|,
literal|'x'
argument_list|)
decl_stmt|;
name|ba
operator|.
name|append
argument_list|(
name|ba2
argument_list|)
expr_stmt|;
name|ba
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|latin1Uppercasing_qt54
name|void
name|tst_qbytearray
operator|::
name|latin1Uppercasing_qt54
parameter_list|()
block|{
name|QByteArray
name|s
init|=
name|sourcecode
decl_stmt|;
name|s
operator|.
name|detach
argument_list|()
expr_stmt|;
comment|// the following was copied from qbytearray.cpp (except for the QBENCHMARK macro):
name|uchar
modifier|*
name|p_orig
init|=
cast|reinterpret_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|s
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|uchar
modifier|*
name|e
init|=
cast|reinterpret_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|s
operator|.
name|end
argument_list|()
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|uchar
modifier|*
name|p
init|=
name|p_orig
decl_stmt|;
if|if
condition|(
name|p
condition|)
block|{
while|while
condition|(
name|p
operator|!=
name|e
condition|)
block|{
operator|*
name|p
operator|=
name|QChar
operator|::
name|toLower
argument_list|(
operator|(
name|ushort
operator|)
operator|*
name|p
argument_list|)
expr_stmt|;
name|p
operator|++
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_comment
comment|/* #!/usr/bin/perl -l use feature "unicode_strings" for (0..255) {     $up = uc(chr($_));     $up = chr($_) if ord($up)> 0x100 || length $up> 1;     printf "0x%02x,", ord($up);     print "" if ($_& 0xf) == 0xf; } */
end_comment
begin_decl_stmt
DECL|variable|uppercased
specifier|static
specifier|const
name|uchar
name|uppercased
index|[
literal|256
index|]
init|=
block|{
literal|0x00
block|,
literal|0x01
block|,
literal|0x02
block|,
literal|0x03
block|,
literal|0x04
block|,
literal|0x05
block|,
literal|0x06
block|,
literal|0x07
block|,
literal|0x08
block|,
literal|0x09
block|,
literal|0x0a
block|,
literal|0x0b
block|,
literal|0x0c
block|,
literal|0x0d
block|,
literal|0x0e
block|,
literal|0x0f
block|,
literal|0x10
block|,
literal|0x11
block|,
literal|0x12
block|,
literal|0x13
block|,
literal|0x14
block|,
literal|0x15
block|,
literal|0x16
block|,
literal|0x17
block|,
literal|0x18
block|,
literal|0x19
block|,
literal|0x1a
block|,
literal|0x1b
block|,
literal|0x1c
block|,
literal|0x1d
block|,
literal|0x1e
block|,
literal|0x1f
block|,
literal|0x20
block|,
literal|0x21
block|,
literal|0x22
block|,
literal|0x23
block|,
literal|0x24
block|,
literal|0x25
block|,
literal|0x26
block|,
literal|0x27
block|,
literal|0x28
block|,
literal|0x29
block|,
literal|0x2a
block|,
literal|0x2b
block|,
literal|0x2c
block|,
literal|0x2d
block|,
literal|0x2e
block|,
literal|0x2f
block|,
literal|0x30
block|,
literal|0x31
block|,
literal|0x32
block|,
literal|0x33
block|,
literal|0x34
block|,
literal|0x35
block|,
literal|0x36
block|,
literal|0x37
block|,
literal|0x38
block|,
literal|0x39
block|,
literal|0x3a
block|,
literal|0x3b
block|,
literal|0x3c
block|,
literal|0x3d
block|,
literal|0x3e
block|,
literal|0x3f
block|,
literal|0x40
block|,
literal|0x41
block|,
literal|0x42
block|,
literal|0x43
block|,
literal|0x44
block|,
literal|0x45
block|,
literal|0x46
block|,
literal|0x47
block|,
literal|0x48
block|,
literal|0x49
block|,
literal|0x4a
block|,
literal|0x4b
block|,
literal|0x4c
block|,
literal|0x4d
block|,
literal|0x4e
block|,
literal|0x4f
block|,
literal|0x50
block|,
literal|0x51
block|,
literal|0x52
block|,
literal|0x53
block|,
literal|0x54
block|,
literal|0x55
block|,
literal|0x56
block|,
literal|0x57
block|,
literal|0x58
block|,
literal|0x59
block|,
literal|0x5a
block|,
literal|0x5b
block|,
literal|0x5c
block|,
literal|0x5d
block|,
literal|0x5e
block|,
literal|0x5f
block|,
literal|0x60
block|,
literal|0x41
block|,
literal|0x42
block|,
literal|0x43
block|,
literal|0x44
block|,
literal|0x45
block|,
literal|0x46
block|,
literal|0x47
block|,
literal|0x48
block|,
literal|0x49
block|,
literal|0x4a
block|,
literal|0x4b
block|,
literal|0x4c
block|,
literal|0x4d
block|,
literal|0x4e
block|,
literal|0x4f
block|,
literal|0x50
block|,
literal|0x51
block|,
literal|0x52
block|,
literal|0x53
block|,
literal|0x54
block|,
literal|0x55
block|,
literal|0x56
block|,
literal|0x57
block|,
literal|0x58
block|,
literal|0x59
block|,
literal|0x5a
block|,
literal|0x7b
block|,
literal|0x7c
block|,
literal|0x7d
block|,
literal|0x7e
block|,
literal|0x7f
block|,
literal|0x80
block|,
literal|0x81
block|,
literal|0x82
block|,
literal|0x83
block|,
literal|0x84
block|,
literal|0x85
block|,
literal|0x86
block|,
literal|0x87
block|,
literal|0x88
block|,
literal|0x89
block|,
literal|0x8a
block|,
literal|0x8b
block|,
literal|0x8c
block|,
literal|0x8d
block|,
literal|0x8e
block|,
literal|0x8f
block|,
literal|0x90
block|,
literal|0x91
block|,
literal|0x92
block|,
literal|0x93
block|,
literal|0x94
block|,
literal|0x95
block|,
literal|0x96
block|,
literal|0x97
block|,
literal|0x98
block|,
literal|0x99
block|,
literal|0x9a
block|,
literal|0x9b
block|,
literal|0x9c
block|,
literal|0x9d
block|,
literal|0x9e
block|,
literal|0x9f
block|,
literal|0xa0
block|,
literal|0xa1
block|,
literal|0xa2
block|,
literal|0xa3
block|,
literal|0xa4
block|,
literal|0xa5
block|,
literal|0xa6
block|,
literal|0xa7
block|,
literal|0xa8
block|,
literal|0xa9
block|,
literal|0xaa
block|,
literal|0xab
block|,
literal|0xac
block|,
literal|0xad
block|,
literal|0xae
block|,
literal|0xaf
block|,
literal|0xb0
block|,
literal|0xb1
block|,
literal|0xb2
block|,
literal|0xb3
block|,
literal|0xb4
block|,
literal|0xb5
block|,
literal|0xb6
block|,
literal|0xb7
block|,
literal|0xb8
block|,
literal|0xb9
block|,
literal|0xba
block|,
literal|0xbb
block|,
literal|0xbc
block|,
literal|0xbd
block|,
literal|0xbe
block|,
literal|0xbf
block|,
literal|0xc0
block|,
literal|0xc1
block|,
literal|0xc2
block|,
literal|0xc3
block|,
literal|0xc4
block|,
literal|0xc5
block|,
literal|0xc6
block|,
literal|0xc7
block|,
literal|0xc8
block|,
literal|0xc9
block|,
literal|0xca
block|,
literal|0xcb
block|,
literal|0xcc
block|,
literal|0xcd
block|,
literal|0xce
block|,
literal|0xcf
block|,
literal|0xd0
block|,
literal|0xd1
block|,
literal|0xd2
block|,
literal|0xd3
block|,
literal|0xd4
block|,
literal|0xd5
block|,
literal|0xd6
block|,
literal|0xd7
block|,
literal|0xd8
block|,
literal|0xd9
block|,
literal|0xda
block|,
literal|0xdb
block|,
literal|0xdc
block|,
literal|0xdd
block|,
literal|0xde
block|,
literal|0xdf
block|,
literal|0xc0
block|,
literal|0xc1
block|,
literal|0xc2
block|,
literal|0xc3
block|,
literal|0xc4
block|,
literal|0xc5
block|,
literal|0xc6
block|,
literal|0xc7
block|,
literal|0xc8
block|,
literal|0xc9
block|,
literal|0xca
block|,
literal|0xcb
block|,
literal|0xcc
block|,
literal|0xcd
block|,
literal|0xce
block|,
literal|0xcf
block|,
literal|0xd0
block|,
literal|0xd1
block|,
literal|0xd2
block|,
literal|0xd3
block|,
literal|0xd4
block|,
literal|0xd5
block|,
literal|0xd6
block|,
literal|0xf7
block|,
literal|0xd8
block|,
literal|0xd9
block|,
literal|0xda
block|,
literal|0xdb
block|,
literal|0xdc
block|,
literal|0xdd
block|,
literal|0xde
block|,
literal|0xff
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|latin1Uppercasing_xlate
name|void
name|tst_qbytearray
operator|::
name|latin1Uppercasing_xlate
parameter_list|()
block|{
name|QByteArray
name|output
init|=
name|sourcecode
decl_stmt|;
name|output
operator|.
name|detach
argument_list|()
expr_stmt|;
name|char
modifier|*
name|dst_orig
init|=
name|output
operator|.
name|data
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|src_orig
init|=
name|sourcecode
operator|.
name|constBegin
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|end
init|=
name|sourcecode
operator|.
name|constEnd
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|char
modifier|*
name|dst
init|=
name|dst_orig
decl_stmt|;
for|for
control|(
specifier|const
name|char
modifier|*
name|src
init|=
name|src_orig
init|;
name|src
operator|!=
name|end
condition|;
operator|++
name|src
operator|,
operator|++
name|dst
control|)
operator|*
name|dst
operator|=
name|uppercased
index|[
name|uchar
argument_list|(
operator|*
name|src
argument_list|)
index|]
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|latin1Uppercasing_xlate_checked
name|void
name|tst_qbytearray
operator|::
name|latin1Uppercasing_xlate_checked
parameter_list|()
block|{
name|QByteArray
name|output
init|=
name|sourcecode
decl_stmt|;
name|output
operator|.
name|detach
argument_list|()
expr_stmt|;
name|char
modifier|*
name|dst_orig
init|=
name|output
operator|.
name|data
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|src_orig
init|=
name|sourcecode
operator|.
name|constBegin
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|end
init|=
name|sourcecode
operator|.
name|constEnd
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|char
modifier|*
name|dst
init|=
name|dst_orig
decl_stmt|;
for|for
control|(
specifier|const
name|char
modifier|*
name|src
init|=
name|src_orig
init|;
name|src
operator|!=
name|end
condition|;
operator|++
name|src
operator|,
operator|++
name|dst
control|)
block|{
name|uchar
name|ch
init|=
name|uchar
argument_list|(
operator|*
name|src
argument_list|)
decl_stmt|;
name|uchar
name|converted
init|=
name|uppercased
index|[
name|ch
index|]
decl_stmt|;
if|if
condition|(
name|ch
operator|!=
name|converted
condition|)
operator|*
name|dst
operator|=
name|converted
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|/* #!/bin/perl -l use feature "unicode_strings"; sub categorize($) {     # 'Ã' and 'Ã¿' are lowercase, but we cannot uppercase them     return 0 if $_[0] == 0xDF || $_[0] == 0xFF;     $ch = chr($_[0]);     return 2 if uc($ch) ne $ch;     return 1 if lc($ch) ne $ch;     return 0; } for (0..255) {     printf "%d,", categorize($_);     print "" if ($_& 0xf) == 0xf; } */
end_comment
begin_decl_stmt
DECL|variable|categories
specifier|static
specifier|const
name|char
name|categories
index|[
literal|256
index|]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|2
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|0
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|latin1Uppercasing_category
name|void
name|tst_qbytearray
operator|::
name|latin1Uppercasing_category
parameter_list|()
block|{
name|QByteArray
name|output
init|=
name|sourcecode
decl_stmt|;
name|output
operator|.
name|detach
argument_list|()
expr_stmt|;
name|char
modifier|*
name|dst_orig
init|=
name|output
operator|.
name|data
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|src_orig
init|=
name|sourcecode
operator|.
name|constBegin
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|end
init|=
name|sourcecode
operator|.
name|constEnd
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|char
modifier|*
name|dst
init|=
name|dst_orig
decl_stmt|;
for|for
control|(
specifier|const
name|char
modifier|*
name|src
init|=
name|src_orig
init|;
name|src
operator|!=
name|end
condition|;
operator|++
name|src
operator|,
operator|++
name|dst
control|)
operator|*
name|dst
operator|=
name|categories
index|[
name|uchar
argument_list|(
operator|*
name|src
argument_list|)
index|]
operator|==
literal|1
condition|?
operator|*
name|src
operator|&
operator|~
literal|0x20
else|:
operator|*
name|src
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/* #!/bin/perl -l use feature "unicode_strings"; sub categorize($) {     # 'Ã' and 'Ã¿' are lowercase, but we cannot uppercase them     return 0 if $_[0] == 0xDF || $_[0] == 0xFF;     $ch = chr($_[0]);     return 2 if uc($ch) ne $ch;     return 1 if lc($ch) ne $ch;     return 0; } for $row (0..7) {     $val = 0;     for $col (0..31) {         $val |= (1<<$col)             if categorize($row * 31 + $col) == 2;     }     printf "0x%08x,", $val; } */
end_comment
begin_decl_stmt
DECL|variable|shouldUppercase
specifier|static
specifier|const
name|quint32
name|shouldUppercase
index|[
literal|8
index|]
init|=
block|{
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x3ffffff0
block|,
literal|0x00000000
block|,
literal|0x04000000
block|,
literal|0x00000000
block|,
literal|0xbfffff80
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|bittest
specifier|static
name|bool
name|bittest
parameter_list|(
specifier|const
name|quint32
modifier|*
name|data
parameter_list|,
name|uchar
name|bit
parameter_list|)
block|{
specifier|static
specifier|const
name|unsigned
name|bitsperelem
init|=
sizeof|sizeof
argument_list|(
operator|*
name|data
argument_list|)
operator|*
name|CHAR_BIT
decl_stmt|;
return|return
name|data
index|[
name|bit
operator|/
name|bitsperelem
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|bit
operator|&
operator|(
name|bitsperelem
operator|-
literal|1
operator|)
operator|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|latin1Uppercasing_bitcheck
name|void
name|tst_qbytearray
operator|::
name|latin1Uppercasing_bitcheck
parameter_list|()
block|{
name|QByteArray
name|output
init|=
name|sourcecode
decl_stmt|;
name|output
operator|.
name|detach
argument_list|()
expr_stmt|;
name|char
modifier|*
name|dst_orig
init|=
name|output
operator|.
name|data
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|src_orig
init|=
name|sourcecode
operator|.
name|constBegin
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|end
init|=
name|sourcecode
operator|.
name|constEnd
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|char
modifier|*
name|dst
init|=
name|dst_orig
decl_stmt|;
for|for
control|(
specifier|const
name|char
modifier|*
name|src
init|=
name|src_orig
init|;
name|src
operator|!=
name|end
condition|;
operator|++
name|src
operator|,
operator|++
name|dst
control|)
operator|*
name|dst
operator|=
name|bittest
argument_list|(
name|shouldUppercase
argument_list|,
operator|*
name|src
argument_list|)
condition|?
name|uchar
argument_list|(
operator|*
name|src
argument_list|)
operator|&
operator|~
literal|0x20
else|:
name|uchar
argument_list|(
operator|*
name|src
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qbytearray
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
