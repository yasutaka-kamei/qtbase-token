begin_unit
comment|'#!/usr/bin/env python'
nl|'\n'
comment|'#############################################################################'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).'
nl|'\n'
comment|'## Contact: http://www.qt-project.org/legal'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## This file is part of the test suite of the Qt Toolkit.'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## $QT_BEGIN_LICENSE:LGPL$'
nl|'\n'
comment|'## Commercial License Usage'
nl|'\n'
comment|'## Licensees holding valid commercial Qt licenses may use this file in'
nl|'\n'
comment|'## accordance with the commercial license agreement provided with the'
nl|'\n'
comment|'## Software or, alternatively, in accordance with the terms contained in'
nl|'\n'
comment|'## a written agreement between you and Digia.  For licensing terms and'
nl|'\n'
comment|'## conditions see http://qt.digia.com/licensing.  For further information'
nl|'\n'
comment|'## use the contact form at http://qt.digia.com/contact-us.'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## GNU Lesser General Public License Usage'
nl|'\n'
comment|'## Alternatively, this file may be used under the terms of the GNU Lesser'
nl|'\n'
comment|'## General Public License version 2.1 as published by the Free Software'
nl|'\n'
comment|'## Foundation and appearing in the file LICENSE.LGPL included in the'
nl|'\n'
comment|'## packaging of this file.  Please review the following information to'
nl|'\n'
comment|'## ensure the GNU Lesser General Public License version 2.1 requirements'
nl|'\n'
comment|'## will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## In addition, as a special exception, Digia gives you certain additional'
nl|'\n'
comment|'## rights.  These rights are described in the Digia Qt LGPL Exception'
nl|'\n'
comment|'## version 1.1, included in the file LGPL_EXCEPTION.txt in this package.'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## GNU General Public License Usage'
nl|'\n'
comment|'## Alternatively, this file may be used under the terms of the GNU'
nl|'\n'
comment|'## General Public License version 3.0 as published by the Free Software'
nl|'\n'
comment|'## Foundation and appearing in the file LICENSE.GPL included in the'
nl|'\n'
comment|'## packaging of this file.  Please review the following information to'
nl|'\n'
comment|'## ensure the GNU General Public License version 3.0 requirements will be'
nl|'\n'
comment|'## met: http://www.gnu.org/copyleft/gpl.html.'
nl|'\n'
comment|'##'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## $QT_END_LICENSE$'
nl|'\n'
comment|'##'
nl|'\n'
comment|'#############################################################################'
nl|'\n'
nl|'\n'
name|'import'
name|'re'
newline|'\n'
nl|'\n'
DECL|function|_convert_pattern
name|'def'
name|'_convert_pattern'
op|'('
name|'pattern'
op|')'
op|':'
newline|'\n'
comment|'# patterns from http://www.unicode.org/reports/tr35/#Date_Format_Patterns'
nl|'\n'
indent|'    '
name|'qt_regexps'
op|'='
op|'{'
nl|'\n'
string|'r"yyy{3,}"'
op|':'
string|'"yyyy"'
op|','
comment|'# more that three digits hence convert to four-digit year'
nl|'\n'
string|'r"L"'
op|':'
string|'"M"'
op|','
comment|'# stand-alone month names. not supported.'
nl|'\n'
string|'r"g{1,}"'
op|':'
string|'""'
op|','
comment|'# modified julian day. not supported.'
nl|'\n'
string|'r"S{1,}"'
op|':'
string|'""'
op|','
comment|'# fractional seconds. not supported.'
nl|'\n'
string|'r"A{1,}"'
op|':'
string|'""'
comment|'# milliseconds in day. not supported.'
nl|'\n'
op|'}'
newline|'\n'
name|'qt_patterns'
op|'='
op|'{'
nl|'\n'
string|'"G"'
op|':'
string|'""'
op|','
string|'"GG"'
op|':'
string|'""'
op|','
string|'"GGG"'
op|':'
string|'""'
op|','
string|'"GGGG"'
op|':'
string|'""'
op|','
string|'"GGGGG"'
op|':'
string|'""'
op|','
comment|'# Era. not supported.'
nl|'\n'
string|'"y"'
op|':'
string|'"yyyy"'
op|','
comment|'# four-digit year without leading zeroes'
nl|'\n'
string|'"Q"'
op|':'
string|'""'
op|','
string|'"QQ"'
op|':'
string|'""'
op|','
string|'"QQQ"'
op|':'
string|'""'
op|','
string|'"QQQQ"'
op|':'
string|'""'
op|','
comment|'# quarter. not supported.'
nl|'\n'
string|'"q"'
op|':'
string|'""'
op|','
string|'"qq"'
op|':'
string|'""'
op|','
string|'"qqq"'
op|':'
string|'""'
op|','
string|'"qqqq"'
op|':'
string|'""'
op|','
comment|'# quarter. not supported.'
nl|'\n'
string|'"MMMMM"'
op|':'
string|'"MMM"'
op|','
comment|'# narrow month name.'
nl|'\n'
string|'"LLLLL"'
op|':'
string|'"MMM"'
op|','
comment|'# stand-alone narrow month name.'
nl|'\n'
string|'"l"'
op|':'
string|'""'
op|','
comment|'# special symbol for chinese leap month. not supported.'
nl|'\n'
string|'"w"'
op|':'
string|'""'
op|','
string|'"W"'
op|':'
string|'""'
op|','
comment|'# week of year/month. not supported.'
nl|'\n'
string|'"D"'
op|':'
string|'""'
op|','
string|'"DD"'
op|':'
string|'""'
op|','
string|'"DDD"'
op|':'
string|'""'
op|','
comment|'# day of year. not supported.'
nl|'\n'
string|'"F"'
op|':'
string|'""'
op|','
comment|'# day of week in month. not supported.'
nl|'\n'
string|'"E"'
op|':'
string|'"ddd"'
op|','
string|'"EE"'
op|':'
string|'"ddd"'
op|','
string|'"EEE"'
op|':'
string|'"ddd"'
op|','
string|'"EEEEE"'
op|':'
string|'"ddd"'
op|','
string|'"EEEE"'
op|':'
string|'"dddd"'
op|','
comment|'# day of week'
nl|'\n'
string|'"e"'
op|':'
string|'"ddd"'
op|','
string|'"ee"'
op|':'
string|'"ddd"'
op|','
string|'"eee"'
op|':'
string|'"ddd"'
op|','
string|'"eeeee"'
op|':'
string|'"ddd"'
op|','
string|'"eeee"'
op|':'
string|'"dddd"'
op|','
comment|'# local day of week'
nl|'\n'
string|'"c"'
op|':'
string|'"ddd"'
op|','
string|'"cc"'
op|':'
string|'"ddd"'
op|','
string|'"ccc"'
op|':'
string|'"ddd"'
op|','
string|'"ccccc"'
op|':'
string|'"ddd"'
op|','
string|'"cccc"'
op|':'
string|'"dddd"'
op|','
comment|'# stand-alone local day of week'
nl|'\n'
string|'"a"'
op|':'
string|'"AP"'
op|','
comment|'# AM/PM'
nl|'\n'
string|'"K"'
op|':'
string|'"h"'
op|','
comment|'# Hour 0-11'
nl|'\n'
string|'"k"'
op|':'
string|'"H"'
op|','
comment|'# Hour 1-24'
nl|'\n'
string|'"j"'
op|':'
string|'""'
op|','
comment|'# special reserved symbol.'
nl|'\n'
string|'"z"'
op|':'
string|'"t"'
op|','
string|'"zz"'
op|':'
string|'"t"'
op|','
string|'"zzz"'
op|':'
string|'"t"'
op|','
string|'"zzzz"'
op|':'
string|'"t"'
op|','
comment|'# timezone'
nl|'\n'
string|'"Z"'
op|':'
string|'"t"'
op|','
string|'"ZZ"'
op|':'
string|'"t"'
op|','
string|'"ZZZ"'
op|':'
string|'"t"'
op|','
string|'"ZZZZ"'
op|':'
string|'"t"'
op|','
comment|'# timezone'
nl|'\n'
string|'"v"'
op|':'
string|'"t"'
op|','
string|'"vv"'
op|':'
string|'"t"'
op|','
string|'"vvv"'
op|':'
string|'"t"'
op|','
string|'"vvvv"'
op|':'
string|'"t"'
op|','
comment|'# timezone'
nl|'\n'
string|'"V"'
op|':'
string|'"t"'
op|','
string|'"VV"'
op|':'
string|'"t"'
op|','
string|'"VVV"'
op|':'
string|'"t"'
op|','
string|'"VVVV"'
op|':'
string|'"t"'
comment|'# timezone'
nl|'\n'
op|'}'
newline|'\n'
name|'if'
name|'qt_patterns'
op|'.'
name|'has_key'
op|'('
name|'pattern'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'return'
name|'qt_patterns'
op|'['
name|'pattern'
op|']'
newline|'\n'
dedent|''
name|'for'
name|'r'
op|','
name|'v'
name|'in'
name|'qt_regexps'
op|'.'
name|'items'
op|'('
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pattern'
op|'='
name|'re'
op|'.'
name|'sub'
op|'('
name|'r'
op|','
name|'v'
op|','
name|'pattern'
op|')'
newline|'\n'
dedent|''
name|'return'
name|'pattern'
newline|'\n'
nl|'\n'
DECL|function|convert_date
dedent|''
name|'def'
name|'convert_date'
op|'('
name|'input'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'result'
op|'='
string|'""'
newline|'\n'
name|'patterns'
op|'='
string|'"GyYuQqMLlwWdDFgEecahHKkjmsSAzZvV"'
newline|'\n'
name|'last'
op|'='
string|'""'
newline|'\n'
name|'inquote'
op|'='
number|'0'
newline|'\n'
name|'chars_to_strip'
op|'='
string|'" -"'
newline|'\n'
name|'for'
name|'c'
name|'in'
name|'input'
op|':'
newline|'\n'
indent|'        '
name|'if'
name|'c'
op|'=='
string|'"\'"'
op|':'
newline|'\n'
indent|'            '
name|'inquote'
op|'='
name|'inquote'
op|'+'
number|'1'
newline|'\n'
dedent|''
name|'if'
name|'inquote'
op|'%'
number|'2'
op|'=='
number|'0'
op|':'
newline|'\n'
indent|'            '
name|'if'
name|'c'
name|'in'
name|'patterns'
op|':'
newline|'\n'
indent|'                '
name|'if'
name|'not'
name|'last'
op|':'
newline|'\n'
indent|'                    '
name|'last'
op|'='
name|'c'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'                    '
name|'if'
name|'c'
name|'in'
name|'last'
op|':'
newline|'\n'
indent|'                        '
name|'last'
op|'+='
name|'c'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
comment|'# pattern changed'
nl|'\n'
indent|'                        '
name|'converted'
op|'='
name|'_convert_pattern'
op|'('
name|'last'
op|')'
newline|'\n'
name|'result'
op|'+='
name|'converted'
newline|'\n'
name|'if'
name|'not'
name|'converted'
op|':'
newline|'\n'
indent|'                            '
name|'result'
op|'='
name|'result'
op|'.'
name|'rstrip'
op|'('
name|'chars_to_strip'
op|')'
newline|'\n'
dedent|''
name|'last'
op|'='
name|'c'
newline|'\n'
dedent|''
dedent|''
name|'continue'
newline|'\n'
dedent|''
dedent|''
name|'if'
name|'last'
op|':'
newline|'\n'
comment|'# pattern ended'
nl|'\n'
indent|'            '
name|'converted'
op|'='
name|'_convert_pattern'
op|'('
name|'last'
op|')'
newline|'\n'
name|'result'
op|'+='
name|'converted'
newline|'\n'
name|'if'
name|'not'
name|'converted'
op|':'
newline|'\n'
indent|'                '
name|'result'
op|'='
name|'result'
op|'.'
name|'rstrip'
op|'('
name|'chars_to_strip'
op|')'
newline|'\n'
dedent|''
name|'last'
op|'='
string|'""'
newline|'\n'
dedent|''
name|'result'
op|'+='
name|'c'
newline|'\n'
dedent|''
name|'if'
name|'last'
op|':'
newline|'\n'
indent|'        '
name|'converted'
op|'='
name|'_convert_pattern'
op|'('
name|'last'
op|')'
newline|'\n'
name|'result'
op|'+='
name|'converted'
newline|'\n'
name|'if'
name|'not'
name|'converted'
op|':'
newline|'\n'
indent|'            '
name|'result'
op|'='
name|'result'
op|'.'
name|'rstrip'
op|'('
name|'chars_to_strip'
op|')'
newline|'\n'
dedent|''
dedent|''
name|'return'
name|'result'
op|'.'
name|'lstrip'
op|'('
name|'chars_to_strip'
op|')'
newline|'\n'
dedent|''
endmarker|''
end_unit
