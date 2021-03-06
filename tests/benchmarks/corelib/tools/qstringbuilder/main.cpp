begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// Select one of the scenarios below
end_comment
begin_define
DECL|macro|SCENARIO
define|#
directive|define
name|SCENARIO
value|1
end_define
begin_if
if|#
directive|if
name|SCENARIO
operator|==
literal|1
end_if
begin_comment
comment|// this is the "no harm done" version. Only operator% is active,
end_comment
begin_comment
comment|// with NO_CAST * defined
end_comment
begin_define
DECL|macro|P
define|#
directive|define
name|P
value|%
end_define
begin_undef
DECL|macro|QT_USE_FAST_OPERATOR_PLUS
undef|#
directive|undef
name|QT_USE_FAST_OPERATOR_PLUS
end_undef
begin_undef
DECL|macro|QT_USE_FAST_CONCATENATION
undef|#
directive|undef
name|QT_USE_FAST_CONCATENATION
end_undef
begin_define
DECL|macro|QT_NO_CAST_FROM_ASCII
define|#
directive|define
name|QT_NO_CAST_FROM_ASCII
end_define
begin_define
DECL|macro|QT_NO_CAST_TO_ASCII
define|#
directive|define
name|QT_NO_CAST_TO_ASCII
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|SCENARIO
operator|==
literal|2
end_if
begin_comment
comment|// this is the "full" version. Operator+ is replaced by a QStringBuilder
end_comment
begin_comment
comment|// based version
end_comment
begin_comment
comment|// with NO_CAST * defined
end_comment
begin_define
DECL|macro|P
define|#
directive|define
name|P
value|+
end_define
begin_define
DECL|macro|QT_USE_FAST_OPERATOR_PLUS
define|#
directive|define
name|QT_USE_FAST_OPERATOR_PLUS
end_define
begin_define
DECL|macro|QT_USE_FAST_CONCATENATION
define|#
directive|define
name|QT_USE_FAST_CONCATENATION
end_define
begin_define
DECL|macro|QT_NO_CAST_FROM_ASCII
define|#
directive|define
name|QT_NO_CAST_FROM_ASCII
end_define
begin_define
DECL|macro|QT_NO_CAST_TO_ASCII
define|#
directive|define
name|QT_NO_CAST_TO_ASCII
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|SCENARIO
operator|==
literal|3
end_if
begin_comment
comment|// this is the "no harm done" version. Only operator% is active,
end_comment
begin_comment
comment|// with NO_CAST * _not_ defined
end_comment
begin_define
DECL|macro|P
define|#
directive|define
name|P
value|%
end_define
begin_undef
DECL|macro|QT_USE_FAST_OPERATOR_PLUS
undef|#
directive|undef
name|QT_USE_FAST_OPERATOR_PLUS
end_undef
begin_undef
DECL|macro|QT_USE_FAST_CONCATENATION
undef|#
directive|undef
name|QT_USE_FAST_CONCATENATION
end_undef
begin_undef
DECL|macro|QT_NO_CAST_FROM_ASCII
undef|#
directive|undef
name|QT_NO_CAST_FROM_ASCII
end_undef
begin_undef
DECL|macro|QT_NO_CAST_TO_ASCII
undef|#
directive|undef
name|QT_NO_CAST_TO_ASCII
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|SCENARIO
operator|==
literal|4
end_if
begin_comment
comment|// this is the "full" version. Operator+ is replaced by a QStringBuilder
end_comment
begin_comment
comment|// based version
end_comment
begin_comment
comment|// with NO_CAST * _not_ defined
end_comment
begin_define
DECL|macro|P
define|#
directive|define
name|P
value|+
end_define
begin_define
DECL|macro|QT_USE_FAST_OPERATOR_PLUS
define|#
directive|define
name|QT_USE_FAST_OPERATOR_PLUS
end_define
begin_define
DECL|macro|QT_USE_FAST_CONCATENATION
define|#
directive|define
name|QT_USE_FAST_CONCATENATION
end_define
begin_undef
DECL|macro|QT_NO_CAST_FROM_ASCII
undef|#
directive|undef
name|QT_NO_CAST_FROM_ASCII
end_undef
begin_undef
DECL|macro|QT_NO_CAST_TO_ASCII
undef|#
directive|undef
name|QT_NO_CAST_TO_ASCII
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qstringbuilder.h>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<string>
end_include
begin_define
DECL|macro|COMPARE
define|#
directive|define
name|COMPARE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|QCOMPARE(a, b)
end_define
begin_comment
comment|//#define COMPARE(a, b)
end_comment
begin_define
DECL|macro|SEP
define|#
directive|define
name|SEP
parameter_list|(
name|s
parameter_list|)
value|qDebug()<< "\n\n-------- " s "  ---------";
end_define
begin_define
DECL|macro|LITERAL
define|#
directive|define
name|LITERAL
value|"some string literal"
end_define
begin_class
DECL|class|tst_qstringbuilder
class|class
name|tst_qstringbuilder
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_qstringbuilder
name|tst_qstringbuilder
parameter_list|()
member_init_list|:
name|l1literal
argument_list|(
name|LITERAL
argument_list|)
member_init_list|,
name|l1string
argument_list|(
name|LITERAL
argument_list|)
member_init_list|,
name|ba
argument_list|(
name|LITERAL
argument_list|)
member_init_list|,
name|string
argument_list|(
name|l1string
argument_list|)
member_init_list|,
name|stdstring
argument_list|(
name|LITERAL
argument_list|)
member_init_list|,
name|stringref
argument_list|(
operator|&
name|string
argument_list|,
literal|2
argument_list|,
literal|10
argument_list|)
member_init_list|,
name|achar
argument_list|(
literal|'c'
argument_list|)
member_init_list|,
name|r2
argument_list|(
name|QLatin1String
argument_list|(
argument|LITERAL LITERAL
argument_list|)
argument_list|)
member_init_list|,
name|r3
argument_list|(
name|QLatin1String
argument_list|(
argument|LITERAL LITERAL LITERAL
argument_list|)
argument_list|)
member_init_list|,
name|r4
argument_list|(
name|QLatin1String
argument_list|(
argument|LITERAL LITERAL LITERAL LITERAL
argument_list|)
argument_list|)
member_init_list|,
name|r5
argument_list|(
name|QLatin1String
argument_list|(
argument|LITERAL LITERAL LITERAL LITERAL LITERAL
argument_list|)
argument_list|)
block|{}
public|public:
DECL|enumerator|N
enum|enum
block|{
name|N
init|=
literal|10000
block|}
enum|;
DECL|function|run_traditional
name|int
name|run_traditional
parameter_list|()
block|{
name|int
name|s
init|=
literal|0
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
name|N
condition|;
operator|++
name|i
control|)
block|{
if|#
directive|if
literal|0
block|s += QString(l1string + l1string).size();             s += QString(l1string + l1string + l1string).size();             s += QString(l1string + l1string + l1string + l1string).size();             s += QString(l1string + l1string + l1string + l1string + l1string).size();
endif|#
directive|endif
name|s
operator|+=
name|QString
argument_list|(
name|achar
operator|+
name|l1string
operator|+
name|achar
argument_list|)
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
return|return
name|s
return|;
block|}
DECL|function|run_builder
name|int
name|run_builder
parameter_list|()
block|{
name|int
name|s
init|=
literal|0
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
name|N
condition|;
operator|++
name|i
control|)
block|{
if|#
directive|if
literal|0
block|s += QString(l1literal P l1literal).size();             s += QString(l1literal P l1literal P l1literal).size();             s += QString(l1literal P l1literal P l1literal P l1literal).size();             s += QString(l1literal P l1literal P l1literal P l1literal P l1literal).size();
endif|#
directive|endif
name|s
operator|+=
name|QString
argument_list|(
name|achar
operator|%
name|l1literal
operator|%
name|achar
argument_list|)
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
return|return
name|s
return|;
block|}
private|private
name|slots
private|:
DECL|function|separator_0
name|void
name|separator_0
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"\nIn each block the QStringBuilder based result appear first "
literal|"(with a 'b_' prefix), QStringBased second ('q_' prefix), std::string "
literal|"last ('s_' prefix)\n"
expr_stmt|;
block|}
DECL|function|separator_1
name|void
name|separator_1
parameter_list|()
block|{
name|SEP
argument_list|(
literal|"literal + literal  (builder first)"
argument_list|)
expr_stmt|;
block|}
DECL|function|b_2_l1literal
name|void
name|b_2_l1literal
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|l1literal
name|P
name|l1literal
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_CAST_FROM_ASCII
DECL|function|b_l1literal_LITERAL
name|void
name|b_l1literal_LITERAL
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|l1literal
name|P
name|LITERAL
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
DECL|function|q_2_l1string
name|void
name|q_2_l1string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|l1string
operator|+
name|l1string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
block|}
DECL|function|separator_2
name|void
name|separator_2
parameter_list|()
block|{
name|SEP
argument_list|(
literal|"2 strings"
argument_list|)
expr_stmt|;
block|}
DECL|function|b_2_string
name|void
name|b_2_string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|string
name|P
name|string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
block|}
DECL|function|q_2_string
name|void
name|q_2_string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|string
operator|+
name|string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
block|}
DECL|function|s_2_string
name|void
name|s_2_string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|stdr
operator|=
name|stdstring
operator|+
name|stdstring
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|stdr
argument_list|,
name|stdstring
operator|+
name|stdstring
argument_list|)
expr_stmt|;
block|}
DECL|function|separator_2c
name|void
name|separator_2c
parameter_list|()
block|{
name|SEP
argument_list|(
literal|"2 string refs"
argument_list|)
expr_stmt|;
block|}
DECL|function|b_2_stringref
name|void
name|b_2_stringref
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|stringref
operator|%
name|stringref
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|QString
argument_list|(
name|stringref
operator|.
name|toString
argument_list|()
operator|+
name|stringref
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|q_2_stringref
name|void
name|q_2_stringref
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|stringref
operator|.
name|toString
argument_list|()
operator|+
name|stringref
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|QString
argument_list|(
name|stringref
operator|%
name|stringref
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|separator_2b
name|void
name|separator_2b
parameter_list|()
block|{
name|SEP
argument_list|(
literal|"3 strings"
argument_list|)
expr_stmt|;
block|}
DECL|function|b_3_string
name|void
name|b_3_string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|string
name|P
name|string
name|P
name|string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r3
argument_list|)
expr_stmt|;
block|}
DECL|function|q_3_string
name|void
name|q_3_string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|string
operator|+
name|string
operator|+
name|string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r3
argument_list|)
expr_stmt|;
block|}
DECL|function|s_3_string
name|void
name|s_3_string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|stdr
operator|=
name|stdstring
operator|+
name|stdstring
operator|+
name|stdstring
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|stdr
argument_list|,
name|stdstring
operator|+
name|stdstring
operator|+
name|stdstring
argument_list|)
expr_stmt|;
block|}
DECL|function|separator_2e
name|void
name|separator_2e
parameter_list|()
block|{
name|SEP
argument_list|(
literal|"4 strings"
argument_list|)
expr_stmt|;
block|}
DECL|function|b_4_string
name|void
name|b_4_string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|string
name|P
name|string
name|P
name|string
name|P
name|string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r4
argument_list|)
expr_stmt|;
block|}
DECL|function|q_4_string
name|void
name|q_4_string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|string
operator|+
name|string
operator|+
name|string
operator|+
name|string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r4
argument_list|)
expr_stmt|;
block|}
DECL|function|s_4_string
name|void
name|s_4_string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|stdr
operator|=
name|stdstring
operator|+
name|stdstring
operator|+
name|stdstring
operator|+
name|stdstring
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|stdr
argument_list|,
name|stdstring
operator|+
name|stdstring
operator|+
name|stdstring
operator|+
name|stdstring
argument_list|)
expr_stmt|;
block|}
DECL|function|separator_2a
name|void
name|separator_2a
parameter_list|()
block|{
name|SEP
argument_list|(
literal|"string + literal  (builder first)"
argument_list|)
expr_stmt|;
block|}
DECL|function|b_string_l1literal
name|void
name|b_string_l1literal
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|string
operator|%
name|l1literal
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_CAST_FROM_ASCII
DECL|function|b_string_LITERAL
name|void
name|b_string_LITERAL
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|string
name|P
name|LITERAL
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
block|}
DECL|function|b_LITERAL_string
name|void
name|b_LITERAL_string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|LITERAL
name|P
name|string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
DECL|function|b_string_l1string
name|void
name|b_string_l1string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|string
name|P
name|l1string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
block|}
DECL|function|q_string_l1literal
name|void
name|q_string_l1literal
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|string
operator|+
name|l1string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
block|}
DECL|function|q_string_l1string
name|void
name|q_string_l1string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|string
operator|+
name|l1string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r2
argument_list|)
expr_stmt|;
block|}
DECL|function|s_LITERAL_string
name|void
name|s_LITERAL_string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|stdr
operator|=
name|LITERAL
operator|+
name|stdstring
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|stdr
argument_list|,
name|stdstring
operator|+
name|stdstring
argument_list|)
expr_stmt|;
block|}
DECL|function|separator_3
name|void
name|separator_3
parameter_list|()
block|{
name|SEP
argument_list|(
literal|"3 literals"
argument_list|)
expr_stmt|;
block|}
DECL|function|b_3_l1literal
name|void
name|b_3_l1literal
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|l1literal
name|P
name|l1literal
name|P
name|l1literal
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r3
argument_list|)
expr_stmt|;
block|}
DECL|function|q_3_l1string
name|void
name|q_3_l1string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|l1string
operator|+
name|l1string
operator|+
name|l1string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r3
argument_list|)
expr_stmt|;
block|}
DECL|function|s_3_l1string
name|void
name|s_3_l1string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|stdr
operator|=
name|stdstring
operator|+
name|LITERAL
operator|+
name|LITERAL
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|stdr
argument_list|,
name|stdstring
operator|+
name|stdstring
operator|+
name|stdstring
argument_list|)
expr_stmt|;
block|}
DECL|function|separator_4
name|void
name|separator_4
parameter_list|()
block|{
name|SEP
argument_list|(
literal|"4 literals"
argument_list|)
expr_stmt|;
block|}
DECL|function|b_4_l1literal
name|void
name|b_4_l1literal
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|l1literal
name|P
name|l1literal
name|P
name|l1literal
name|P
name|l1literal
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r4
argument_list|)
expr_stmt|;
block|}
DECL|function|q_4_l1string
name|void
name|q_4_l1string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|l1string
operator|+
name|l1string
operator|+
name|l1string
operator|+
name|l1string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r4
argument_list|)
expr_stmt|;
block|}
DECL|function|separator_5
name|void
name|separator_5
parameter_list|()
block|{
name|SEP
argument_list|(
literal|"5 literals"
argument_list|)
expr_stmt|;
block|}
DECL|function|b_5_l1literal
name|void
name|b_5_l1literal
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|l1literal
name|P
name|l1literal
name|P
name|l1literal
name|P
name|l1literal
name|P
name|l1literal
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r5
argument_list|)
expr_stmt|;
block|}
DECL|function|q_5_l1string
name|void
name|q_5_l1string
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|l1string
operator|+
name|l1string
operator|+
name|l1string
operator|+
name|l1string
operator|+
name|l1string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r5
argument_list|)
expr_stmt|;
block|}
DECL|function|separator_6
name|void
name|separator_6
parameter_list|()
block|{
name|SEP
argument_list|(
literal|"4 chars"
argument_list|)
expr_stmt|;
block|}
DECL|function|b_string_4_char
name|void
name|b_string_4_char
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|string
operator|+
name|achar
operator|+
name|achar
operator|+
name|achar
operator|+
name|achar
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|QString
argument_list|(
argument|string P achar P achar P achar P achar
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|q_string_4_char
name|void
name|q_string_4_char
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|string
operator|+
name|achar
operator|+
name|achar
operator|+
name|achar
operator|+
name|achar
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|QString
argument_list|(
argument|string P achar P achar P achar P achar
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|s_string_4_char
name|void
name|s_string_4_char
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|stdr
operator|=
name|stdstring
operator|+
literal|'c'
operator|+
literal|'c'
operator|+
literal|'c'
operator|+
literal|'c'
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|stdr
argument_list|,
name|stdstring
operator|+
literal|'c'
operator|+
literal|'c'
operator|+
literal|'c'
operator|+
literal|'c'
argument_list|)
expr_stmt|;
block|}
DECL|function|separator_7
name|void
name|separator_7
parameter_list|()
block|{
name|SEP
argument_list|(
literal|"char + string + char"
argument_list|)
expr_stmt|;
block|}
DECL|function|b_char_string_char
name|void
name|b_char_string_char
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|achar
operator|+
name|string
operator|+
name|achar
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|QString
argument_list|(
argument|achar P string P achar
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|q_char_string_char
name|void
name|q_char_string_char
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|=
name|achar
operator|+
name|string
operator|+
name|achar
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|QString
argument_list|(
argument|achar P string P achar
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|s_char_string_char
name|void
name|s_char_string_char
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|stdr
operator|=
literal|'c'
operator|+
name|stdstring
operator|+
literal|'c'
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|stdr
argument_list|,
literal|'c'
operator|+
name|stdstring
operator|+
literal|'c'
argument_list|)
expr_stmt|;
block|}
DECL|function|separator_8
name|void
name|separator_8
parameter_list|()
block|{
name|SEP
argument_list|(
literal|"string.arg"
argument_list|)
expr_stmt|;
block|}
DECL|function|b_string_arg
name|void
name|b_string_arg
parameter_list|()
block|{
specifier|const
name|QString
name|pattern
init|=
name|l1string
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"%1"
argument_list|)
operator|+
name|l1string
decl_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|l1literal
name|P
name|string
name|P
name|l1literal
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r3
argument_list|)
expr_stmt|;
block|}
DECL|function|q_string_arg
name|void
name|q_string_arg
parameter_list|()
block|{
specifier|const
name|QString
name|pattern
init|=
name|l1string
operator|+
name|QLatin1String
argument_list|(
literal|"%1"
argument_list|)
operator|+
name|l1string
decl_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|pattern
operator|.
name|arg
argument_list|(
name|string
argument_list|)
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r3
argument_list|)
expr_stmt|;
block|}
DECL|function|q_bytearray_arg
name|void
name|q_bytearray_arg
parameter_list|()
block|{
name|QByteArray
name|result
decl_stmt|;
name|QBENCHMARK
block|{
name|result
operator|=
name|ba
operator|+
name|ba
operator|+
name|ba
expr_stmt|;
block|}
block|}
DECL|function|separator_9
name|void
name|separator_9
parameter_list|()
block|{
name|SEP
argument_list|(
literal|"QString::reserve()"
argument_list|)
expr_stmt|;
block|}
DECL|function|b_reserve
name|void
name|b_reserve
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|.
name|clear
argument_list|()
expr_stmt|;
name|r
operator|=
name|string
name|P
name|string
name|P
name|string
name|P
name|string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r4
argument_list|)
expr_stmt|;
block|}
DECL|function|b_reserve_lit
name|void
name|b_reserve_lit
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|.
name|clear
argument_list|()
expr_stmt|;
name|r
operator|=
name|string
name|P
name|l1literal
name|P
name|string
name|P
name|string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r4
argument_list|)
expr_stmt|;
block|}
DECL|function|s_reserve
name|void
name|s_reserve
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|.
name|clear
argument_list|()
expr_stmt|;
name|r
operator|.
name|reserve
argument_list|(
name|string
operator|.
name|size
argument_list|()
operator|+
name|string
operator|.
name|size
argument_list|()
operator|+
name|string
operator|.
name|size
argument_list|()
operator|+
name|string
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|r
operator|+=
name|string
expr_stmt|;
name|r
operator|+=
name|string
expr_stmt|;
name|r
operator|+=
name|string
expr_stmt|;
name|r
operator|+=
name|string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r4
argument_list|)
expr_stmt|;
block|}
DECL|function|s_reserve_lit
name|void
name|s_reserve_lit
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|r
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|//r.reserve(string.size() + qstrlen(l1string.latin1())
comment|//    + string.size() + string.size());
name|r
operator|.
name|reserve
argument_list|(
literal|1024
argument_list|)
expr_stmt|;
name|r
operator|+=
name|string
expr_stmt|;
name|r
operator|+=
name|l1string
expr_stmt|;
name|r
operator|+=
name|string
expr_stmt|;
name|r
operator|+=
name|string
expr_stmt|;
block|}
name|COMPARE
argument_list|(
name|r
argument_list|,
name|r4
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|member|l1literal
specifier|const
name|QLatin1Literal
name|l1literal
decl_stmt|;
DECL|member|l1string
specifier|const
name|QLatin1String
name|l1string
decl_stmt|;
DECL|member|ba
specifier|const
name|QByteArray
name|ba
decl_stmt|;
DECL|member|string
specifier|const
name|QString
name|string
decl_stmt|;
DECL|member|stdstring
specifier|const
name|std
operator|::
name|string
name|stdstring
decl_stmt|;
DECL|member|stringref
specifier|const
name|QStringRef
name|stringref
decl_stmt|;
DECL|member|achar
specifier|const
name|QLatin1Char
name|achar
decl_stmt|;
DECL|member|r2
DECL|member|r3
DECL|member|r4
DECL|member|r5
specifier|const
name|QString
name|r2
decl_stmt|,
name|r3
decl_stmt|,
name|r4
decl_stmt|,
name|r5
decl_stmt|;
comment|// short cuts for results
DECL|member|r
name|QString
name|r
decl_stmt|;
DECL|member|stdr
name|std
operator|::
name|string
name|stdr
decl_stmt|;
block|}
class|;
end_class
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qstringbuilder
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
