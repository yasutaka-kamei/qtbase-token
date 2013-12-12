begin_unit
comment|'#!/usr/bin/env python3'
nl|'\n'
comment|'#############################################################################'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).'
nl|'\n'
comment|'## Contact: http://www.qt-project.org/legal'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## This file is part of the release tools of the Qt Toolkit.'
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
comment|"#regenerate all test's output"
nl|'\n'
nl|'\n'
name|'import'
name|'os'
newline|'\n'
name|'import'
name|'sys'
newline|'\n'
name|'import'
name|'subprocess'
newline|'\n'
name|'import'
name|'re'
newline|'\n'
nl|'\n'
DECL|variable|formats
name|'formats'
op|'='
op|'['
string|"'xml'"
op|','
string|"'txt'"
op|','
string|"'xunitxml'"
op|','
string|"'lightxml'"
op|']'
newline|'\n'
nl|'\n'
DECL|variable|qtver
name|'qtver'
op|'='
name|'subprocess'
op|'.'
name|'check_output'
op|'('
op|'['
string|"'qmake'"
op|','
string|"'-query'"
op|','
string|"'QT_VERSION'"
op|']'
op|')'
op|'.'
name|'strip'
op|'('
op|')'
op|'.'
name|'decode'
op|'('
string|"'utf-8'"
op|')'
newline|'\n'
DECL|variable|rootPath
name|'rootPath'
op|'='
name|'os'
op|'.'
name|'getcwd'
op|'('
op|')'
newline|'\n'
nl|'\n'
name|'isWindows'
op|'='
name|'sys'
op|'.'
name|'platform'
op|'=='
string|"'win32'"
newline|'\n'
nl|'\n'
DECL|variable|replacements
name|'replacements'
op|'='
op|'['
nl|'\n'
op|'('
name|'qtver'
op|','
string|"r'@INSERT_QT_VERSION_HERE@'"
op|')'
op|','
nl|'\n'
op|'('
name|'rootPath'
op|'.'
name|'encode'
op|'('
string|"'unicode-escape'"
op|')'
op|'.'
name|'decode'
op|'('
string|"'utf-8'"
op|')'
op|','
string|"r''"
op|')'
op|','
nl|'\n'
op|'('
string|'r\'<Duration msecs="\\d+"/>\''
op|','
string|'r\'<Duration msecs="0"/>\''
op|')'
op|','
nl|'\n'
op|']'
newline|'\n'
nl|'\n'
DECL|variable|extraArgs
name|'extraArgs'
op|'='
op|'{'
nl|'\n'
string|'"commandlinedata"'
op|':'
string|'"fiveTablePasses fiveTablePasses:fiveTablePasses_data1 -v2"'
op|','
nl|'\n'
string|'"benchlibcallgrind"'
op|':'
string|'"-callgrind"'
op|','
nl|'\n'
string|'"benchlibeventcounter"'
op|':'
string|'"-eventcounter"'
op|','
nl|'\n'
string|'"benchliboptions"'
op|':'
string|'"-eventcounter"'
op|','
nl|'\n'
string|'"benchlibtickcounter"'
op|':'
string|'"-tickcounter"'
op|','
nl|'\n'
string|'"badxml"'
op|':'
string|'"-eventcounter"'
op|','
nl|'\n'
string|'"benchlibcounting"'
op|':'
string|'"-eventcounter"'
op|','
nl|'\n'
string|'"printdatatags"'
op|':'
string|'"-datatags"'
op|','
nl|'\n'
string|'"printdatatagswithglobaltags"'
op|':'
string|'"-datatags"'
op|','
nl|'\n'
string|'"silent"'
op|':'
string|'"-silent"'
op|','
nl|'\n'
string|'"verbose1"'
op|':'
string|'"-v1"'
op|','
nl|'\n'
string|'"verbose2"'
op|':'
string|'"-v2"'
op|','
nl|'\n'
op|'}'
newline|'\n'
nl|'\n'
comment|'# Replace all occurrences of searchExp in one file'
nl|'\n'
DECL|function|replaceInFile
name|'def'
name|'replaceInFile'
op|'('
name|'file'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'import'
name|'sys'
newline|'\n'
name|'import'
name|'fileinput'
newline|'\n'
name|'for'
name|'line'
name|'in'
name|'fileinput'
op|'.'
name|'input'
op|'('
name|'file'
op|','
name|'inplace'
op|'='
number|'1'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'for'
name|'searchExp'
op|','
name|'replaceExp'
name|'in'
name|'replacements'
op|':'
newline|'\n'
indent|'            '
name|'line'
op|'='
name|'re'
op|'.'
name|'sub'
op|'('
name|'searchExp'
op|','
name|'replaceExp'
op|','
name|'line'
op|')'
newline|'\n'
dedent|''
name|'sys'
op|'.'
name|'stdout'
op|'.'
name|'write'
op|'('
name|'line'
op|')'
newline|'\n'
nl|'\n'
DECL|function|subdirs
dedent|''
dedent|''
name|'def'
name|'subdirs'
op|'('
op|')'
op|':'
newline|'\n'
indent|'    '
name|'for'
name|'path'
name|'in'
name|'os'
op|'.'
name|'listdir'
op|'('
string|"'.'"
op|')'
op|':'
newline|'\n'
indent|'        '
name|'if'
name|'os'
op|'.'
name|'path'
op|'.'
name|'isdir'
op|'('
string|"'./'"
op|'+'
name|'path'
op|')'
op|':'
newline|'\n'
indent|'            '
name|'yield'
name|'path'
newline|'\n'
nl|'\n'
DECL|function|getTestForPath
dedent|''
dedent|''
dedent|''
name|'def'
name|'getTestForPath'
op|'('
name|'path'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'if'
name|'isWindows'
op|':'
newline|'\n'
indent|'        '
name|'testpath'
op|'='
name|'path'
op|'+'
string|"'\\\\'"
op|'+'
name|'path'
op|'+'
string|"'.exe'"
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'        '
name|'testpath'
op|'='
name|'path'
op|'+'
string|"'/'"
op|'+'
name|'path'
newline|'\n'
dedent|''
name|'return'
name|'testpath'
newline|'\n'
nl|'\n'
DECL|function|generateTestData
dedent|''
name|'def'
name|'generateTestData'
op|'('
name|'testname'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'print'
op|'('
string|'"  running "'
op|'+'
name|'testname'
op|')'
newline|'\n'
name|'for'
name|'format'
name|'in'
name|'formats'
op|':'
newline|'\n'
indent|'        '
name|'cmd'
op|'='
op|'['
name|'getTestForPath'
op|'('
name|'testname'
op|')'
op|'+'
string|"' -'"
op|'+'
name|'format'
op|'+'
string|"' '"
op|'+'
name|'extraArgs'
op|'.'
name|'get'
op|'('
name|'testname'
op|','
string|"''"
op|')'
op|']'
newline|'\n'
name|'result'
op|'='
string|"'expected_'"
op|'+'
name|'testname'
op|'+'
string|"'.'"
op|'+'
name|'format'
newline|'\n'
name|'data'
op|'='
name|'subprocess'
op|'.'
name|'Popen'
op|'('
name|'cmd'
op|','
name|'stdout'
op|'='
name|'subprocess'
op|'.'
name|'PIPE'
op|','
name|'shell'
op|'='
name|'True'
op|')'
op|'.'
name|'communicate'
op|'('
op|')'
op|'['
number|'0'
op|']'
newline|'\n'
name|'out'
op|'='
name|'open'
op|'('
name|'result'
op|','
string|"'w'"
op|')'
newline|'\n'
name|'out'
op|'.'
name|'write'
op|'('
name|'data'
op|'.'
name|'decode'
op|'('
string|"'utf-8'"
op|')'
op|')'
newline|'\n'
name|'out'
op|'.'
name|'close'
op|'('
op|')'
newline|'\n'
name|'replaceInFile'
op|'('
name|'result'
op|')'
newline|'\n'
nl|'\n'
dedent|''
dedent|''
name|'if'
name|'isWindows'
op|':'
newline|'\n'
indent|'    '
name|'print'
op|'('
string|'"This script does not work on Windows."'
op|')'
newline|'\n'
name|'exit'
op|'('
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'print'
op|'('
string|'"Generating test results for: "'
op|'+'
name|'qtver'
op|'+'
string|'" in: "'
op|'+'
name|'rootPath'
op|')'
newline|'\n'
name|'for'
name|'path'
name|'in'
name|'subdirs'
op|'('
op|')'
op|':'
newline|'\n'
indent|'    '
name|'if'
name|'os'
op|'.'
name|'path'
op|'.'
name|'isfile'
op|'('
name|'getTestForPath'
op|'('
name|'path'
op|')'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'generateTestData'
op|'('
name|'path'
op|')'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'        '
name|'print'
op|'('
string|'"Warning: directory "'
op|'+'
name|'path'
op|'+'
string|'" contains no test executable"'
op|')'
newline|'\n'
dedent|''
dedent|''
endmarker|''
end_unit
