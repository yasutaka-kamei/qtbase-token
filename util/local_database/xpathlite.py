begin_unit
comment|'#!/usr/bin/env python'
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
name|'sys'
newline|'\n'
name|'import'
name|'os'
newline|'\n'
name|'import'
name|'xml'
op|'.'
name|'dom'
op|'.'
name|'minidom'
newline|'\n'
nl|'\n'
DECL|variable|doc_cache
name|'doc_cache'
op|'='
op|'{'
op|'}'
newline|'\n'
nl|'\n'
DECL|class|DraftResolution
name|'class'
name|'DraftResolution'
op|':'
newline|'\n'
comment|'# See http://www.unicode.org/cldr/process.html for description'
nl|'\n'
DECL|variable|unconfirmed
indent|'    '
name|'unconfirmed'
op|'='
string|"'unconfirmed'"
newline|'\n'
DECL|variable|provisional
name|'provisional'
op|'='
string|"'provisional'"
newline|'\n'
DECL|variable|contributed
name|'contributed'
op|'='
string|"'contributed'"
newline|'\n'
DECL|variable|approved
name|'approved'
op|'='
string|"'approved'"
newline|'\n'
DECL|variable|_values
name|'_values'
op|'='
op|'{'
name|'unconfirmed'
op|':'
number|'1'
op|','
name|'provisional'
op|':'
number|'2'
op|','
name|'contributed'
op|':'
number|'3'
op|','
name|'approved'
op|':'
number|'4'
op|'}'
newline|'\n'
DECL|member|__init__
name|'def'
name|'__init__'
op|'('
name|'self'
op|','
name|'resolution'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'self'
op|'.'
name|'resolution'
op|'='
name|'resolution'
newline|'\n'
DECL|member|toInt
dedent|''
name|'def'
name|'toInt'
op|'('
name|'self'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'return'
name|'DraftResolution'
op|'.'
name|'_values'
op|'['
name|'self'
op|'.'
name|'resolution'
op|']'
newline|'\n'
nl|'\n'
DECL|class|Error
dedent|''
dedent|''
name|'class'
name|'Error'
op|':'
newline|'\n'
DECL|member|__init__
indent|'    '
name|'def'
name|'__init__'
op|'('
name|'self'
op|','
name|'msg'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'self'
op|'.'
name|'msg'
op|'='
name|'msg'
newline|'\n'
DECL|member|__str__
dedent|''
name|'def'
name|'__str__'
op|'('
name|'self'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'return'
name|'self'
op|'.'
name|'msg'
newline|'\n'
nl|'\n'
DECL|function|findChild
dedent|''
dedent|''
name|'def'
name|'findChild'
op|'('
name|'parent'
op|','
name|'tag_name'
op|','
name|'arg_name'
op|'='
name|'None'
op|','
name|'arg_value'
op|'='
name|'None'
op|','
name|'draft'
op|'='
name|'None'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'for'
name|'node'
name|'in'
name|'parent'
op|'.'
name|'childNodes'
op|':'
newline|'\n'
indent|'        '
name|'if'
name|'node'
op|'.'
name|'nodeType'
op|'!='
name|'node'
op|'.'
name|'ELEMENT_NODE'
op|':'
newline|'\n'
indent|'            '
name|'continue'
newline|'\n'
dedent|''
name|'if'
name|'node'
op|'.'
name|'nodeName'
op|'!='
name|'tag_name'
op|':'
newline|'\n'
indent|'            '
name|'continue'
newline|'\n'
dedent|''
name|'if'
name|'arg_value'
op|':'
newline|'\n'
indent|'            '
name|'if'
name|'not'
name|'node'
op|'.'
name|'attributes'
op|'.'
name|'has_key'
op|'('
name|'arg_name'
op|')'
op|':'
newline|'\n'
indent|'                '
name|'continue'
newline|'\n'
dedent|''
name|'if'
name|'node'
op|'.'
name|'attributes'
op|'['
name|'arg_name'
op|']'
op|'.'
name|'nodeValue'
op|'!='
name|'arg_value'
op|':'
newline|'\n'
indent|'                '
name|'continue'
newline|'\n'
dedent|''
dedent|''
name|'if'
name|'draft'
op|':'
newline|'\n'
indent|'            '
name|'if'
name|'not'
name|'node'
op|'.'
name|'attributes'
op|'.'
name|'has_key'
op|'('
string|"'draft'"
op|')'
op|':'
newline|'\n'
comment|"# if draft is not specified then it's approved"
nl|'\n'
indent|'                '
name|'return'
name|'node'
newline|'\n'
dedent|''
name|'value'
op|'='
name|'node'
op|'.'
name|'attributes'
op|'['
string|"'draft'"
op|']'
op|'.'
name|'nodeValue'
newline|'\n'
name|'value'
op|'='
name|'DraftResolution'
op|'('
name|'value'
op|')'
op|'.'
name|'toInt'
op|'('
op|')'
newline|'\n'
name|'exemplar'
op|'='
name|'DraftResolution'
op|'('
name|'draft'
op|')'
op|'.'
name|'toInt'
op|'('
op|')'
newline|'\n'
name|'if'
name|'exemplar'
op|'>'
name|'value'
op|':'
newline|'\n'
indent|'                '
name|'continue'
newline|'\n'
dedent|''
dedent|''
name|'return'
name|'node'
newline|'\n'
dedent|''
name|'return'
name|'False'
newline|'\n'
nl|'\n'
DECL|function|findTagsInFile
dedent|''
name|'def'
name|'findTagsInFile'
op|'('
name|'file'
op|','
name|'path'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'doc'
op|'='
name|'False'
newline|'\n'
name|'if'
name|'doc_cache'
op|'.'
name|'has_key'
op|'('
name|'file'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'doc'
op|'='
name|'doc_cache'
op|'['
name|'file'
op|']'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'        '
name|'doc'
op|'='
name|'xml'
op|'.'
name|'dom'
op|'.'
name|'minidom'
op|'.'
name|'parse'
op|'('
name|'file'
op|')'
newline|'\n'
name|'doc_cache'
op|'['
name|'file'
op|']'
op|'='
name|'doc'
newline|'\n'
nl|'\n'
dedent|''
name|'elt'
op|'='
name|'doc'
op|'.'
name|'documentElement'
newline|'\n'
name|'tag_spec_list'
op|'='
name|'path'
op|'.'
name|'split'
op|'('
string|'"/"'
op|')'
newline|'\n'
name|'last_entry'
op|'='
name|'None'
newline|'\n'
name|'for'
name|'i'
name|'in'
name|'range'
op|'('
name|'len'
op|'('
name|'tag_spec_list'
op|')'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'tag_spec'
op|'='
name|'tag_spec_list'
op|'['
name|'i'
op|']'
newline|'\n'
name|'tag_name'
op|'='
name|'tag_spec'
newline|'\n'
name|'arg_name'
op|'='
string|"'type'"
newline|'\n'
name|'arg_value'
op|'='
string|"''"
newline|'\n'
name|'left_bracket'
op|'='
name|'tag_spec'
op|'.'
name|'find'
op|'('
string|"'['"
op|')'
newline|'\n'
name|'if'
name|'left_bracket'
op|'!='
op|'-'
number|'1'
op|':'
newline|'\n'
indent|'            '
name|'tag_name'
op|'='
name|'tag_spec'
op|'['
op|':'
name|'left_bracket'
op|']'
newline|'\n'
name|'arg_value'
op|'='
name|'tag_spec'
op|'['
name|'left_bracket'
op|'+'
number|'1'
op|':'
op|'-'
number|'1'
op|']'
op|'.'
name|'split'
op|'('
string|'"="'
op|')'
newline|'\n'
name|'if'
name|'len'
op|'('
name|'arg_value'
op|')'
op|'=='
number|'2'
op|':'
newline|'\n'
indent|'                '
name|'arg_name'
op|'='
name|'arg_value'
op|'['
number|'0'
op|']'
newline|'\n'
name|'arg_value'
op|'='
name|'arg_value'
op|'['
number|'1'
op|']'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'                '
name|'arg_value'
op|'='
name|'arg_value'
op|'['
number|'0'
op|']'
newline|'\n'
dedent|''
dedent|''
name|'elt'
op|'='
name|'findChild'
op|'('
name|'elt'
op|','
name|'tag_name'
op|','
name|'arg_name'
op|','
name|'arg_value'
op|')'
newline|'\n'
name|'if'
name|'not'
name|'elt'
op|':'
newline|'\n'
indent|'            '
name|'return'
name|'None'
newline|'\n'
dedent|''
dedent|''
name|'ret'
op|'='
op|'['
op|']'
newline|'\n'
name|'if'
name|'elt'
op|'.'
name|'childNodes'
op|':'
newline|'\n'
indent|'        '
name|'for'
name|'node'
name|'in'
name|'elt'
op|'.'
name|'childNodes'
op|':'
newline|'\n'
indent|'            '
name|'if'
name|'node'
op|'.'
name|'attributes'
op|':'
newline|'\n'
indent|'                '
name|'element'
op|'='
op|'['
name|'node'
op|'.'
name|'nodeName'
op|','
name|'None'
op|']'
newline|'\n'
name|'element'
op|'['
number|'1'
op|']'
op|'='
name|'node'
op|'.'
name|'attributes'
op|'.'
name|'items'
op|'('
op|')'
newline|'\n'
name|'ret'
op|'.'
name|'append'
op|'('
name|'element'
op|')'
newline|'\n'
dedent|''
dedent|''
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'        '
name|'if'
name|'elt'
op|'.'
name|'attributes'
op|':'
newline|'\n'
indent|'            '
name|'element'
op|'='
op|'['
name|'elt'
op|'.'
name|'nodeName'
op|','
name|'None'
op|']'
newline|'\n'
name|'element'
op|'['
number|'1'
op|']'
op|'='
name|'elt'
op|'.'
name|'attributes'
op|'.'
name|'items'
op|'('
op|')'
newline|'\n'
name|'ret'
op|'.'
name|'append'
op|'('
name|'element'
op|')'
newline|'\n'
dedent|''
dedent|''
name|'return'
name|'ret'
newline|'\n'
nl|'\n'
DECL|function|_findEntryInFile
dedent|''
name|'def'
name|'_findEntryInFile'
op|'('
name|'file'
op|','
name|'path'
op|','
name|'draft'
op|'='
name|'None'
op|','
name|'attribute'
op|'='
name|'None'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'doc'
op|'='
name|'False'
newline|'\n'
name|'if'
name|'doc_cache'
op|'.'
name|'has_key'
op|'('
name|'file'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'doc'
op|'='
name|'doc_cache'
op|'['
name|'file'
op|']'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'        '
name|'doc'
op|'='
name|'xml'
op|'.'
name|'dom'
op|'.'
name|'minidom'
op|'.'
name|'parse'
op|'('
name|'file'
op|')'
newline|'\n'
name|'doc_cache'
op|'['
name|'file'
op|']'
op|'='
name|'doc'
newline|'\n'
nl|'\n'
dedent|''
name|'elt'
op|'='
name|'doc'
op|'.'
name|'documentElement'
newline|'\n'
name|'tag_spec_list'
op|'='
name|'path'
op|'.'
name|'split'
op|'('
string|'"/"'
op|')'
newline|'\n'
name|'last_entry'
op|'='
name|'None'
newline|'\n'
name|'for'
name|'i'
name|'in'
name|'range'
op|'('
name|'len'
op|'('
name|'tag_spec_list'
op|')'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'tag_spec'
op|'='
name|'tag_spec_list'
op|'['
name|'i'
op|']'
newline|'\n'
name|'tag_name'
op|'='
name|'tag_spec'
newline|'\n'
name|'arg_name'
op|'='
string|"'type'"
newline|'\n'
name|'arg_value'
op|'='
string|"''"
newline|'\n'
name|'left_bracket'
op|'='
name|'tag_spec'
op|'.'
name|'find'
op|'('
string|"'['"
op|')'
newline|'\n'
name|'if'
name|'left_bracket'
op|'!='
op|'-'
number|'1'
op|':'
newline|'\n'
indent|'            '
name|'tag_name'
op|'='
name|'tag_spec'
op|'['
op|':'
name|'left_bracket'
op|']'
newline|'\n'
name|'arg_value'
op|'='
name|'tag_spec'
op|'['
name|'left_bracket'
op|'+'
number|'1'
op|':'
op|'-'
number|'1'
op|']'
op|'.'
name|'split'
op|'('
string|'"="'
op|')'
newline|'\n'
name|'if'
name|'len'
op|'('
name|'arg_value'
op|')'
op|'=='
number|'2'
op|':'
newline|'\n'
indent|'                '
name|'arg_name'
op|'='
name|'arg_value'
op|'['
number|'0'
op|']'
op|'.'
name|'replace'
op|'('
string|'"@"'
op|','
string|'""'
op|')'
op|'.'
name|'replace'
op|'('
string|'"\'"'
op|','
string|'""'
op|')'
newline|'\n'
name|'arg_value'
op|'='
name|'arg_value'
op|'['
number|'1'
op|']'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'                '
name|'arg_value'
op|'='
name|'arg_value'
op|'['
number|'0'
op|']'
newline|'\n'
dedent|''
dedent|''
name|'alias'
op|'='
name|'findChild'
op|'('
name|'elt'
op|','
string|"'alias'"
op|')'
newline|'\n'
name|'if'
name|'alias'
name|'and'
name|'alias'
op|'.'
name|'attributes'
op|'['
string|"'source'"
op|']'
op|'.'
name|'nodeValue'
op|'=='
string|"'locale'"
op|':'
newline|'\n'
indent|'            '
name|'path'
op|'='
name|'alias'
op|'.'
name|'attributes'
op|'['
string|"'path'"
op|']'
op|'.'
name|'nodeValue'
newline|'\n'
name|'aliaspath'
op|'='
name|'tag_spec_list'
op|'['
op|':'
name|'i'
op|']'
op|'+'
name|'path'
op|'.'
name|'split'
op|'('
string|'"/"'
op|')'
newline|'\n'
DECL|function|resolve
name|'def'
name|'resolve'
op|'('
name|'x'
op|','
name|'y'
op|')'
op|':'
newline|'\n'
indent|'                '
name|'if'
name|'y'
op|'=='
string|"'..'"
op|':'
newline|'\n'
indent|'                    '
name|'return'
name|'x'
op|'['
op|':'
op|'-'
number|'1'
op|']'
newline|'\n'
dedent|''
name|'return'
name|'x'
op|'+'
op|'['
name|'y'
op|']'
newline|'\n'
comment|'# resolve all dot-dot parts of the path'
nl|'\n'
dedent|''
name|'aliaspath'
op|'='
name|'reduce'
op|'('
name|'resolve'
op|','
name|'aliaspath'
op|','
op|'['
op|']'
op|')'
newline|'\n'
comment|'# remove attribute specification that our xpathlite doesnt support'
nl|'\n'
name|'aliaspath'
op|'='
name|'map'
op|'('
name|'lambda'
name|'x'
op|':'
name|'x'
op|'.'
name|'replace'
op|'('
string|'"@type="'
op|','
string|'""'
op|')'
op|'.'
name|'replace'
op|'('
string|'"\'"'
op|','
string|'""'
op|')'
op|','
name|'aliaspath'
op|')'
newline|'\n'
comment|'# append the remaining path'
nl|'\n'
name|'aliaspath'
op|'='
name|'aliaspath'
op|'+'
name|'tag_spec_list'
op|'['
name|'i'
op|':'
op|']'
newline|'\n'
name|'aliaspath'
op|'='
string|'"/"'
op|'.'
name|'join'
op|'('
name|'aliaspath'
op|')'
newline|'\n'
comment|'# "locale" aliases are special - we need to start lookup from scratch'
nl|'\n'
name|'return'
op|'('
name|'None'
op|','
name|'aliaspath'
op|')'
newline|'\n'
dedent|''
name|'elt'
op|'='
name|'findChild'
op|'('
name|'elt'
op|','
name|'tag_name'
op|','
name|'arg_name'
op|','
name|'arg_value'
op|','
name|'draft'
op|')'
newline|'\n'
name|'if'
name|'not'
name|'elt'
op|':'
newline|'\n'
indent|'            '
name|'return'
op|'('
string|'""'
op|','
name|'None'
op|')'
newline|'\n'
dedent|''
dedent|''
name|'if'
name|'attribute'
name|'is'
name|'not'
name|'None'
op|':'
newline|'\n'
indent|'        '
name|'if'
name|'elt'
op|'.'
name|'attributes'
op|'.'
name|'has_key'
op|'('
name|'attribute'
op|')'
op|':'
newline|'\n'
indent|'            '
name|'return'
op|'('
name|'elt'
op|'.'
name|'attributes'
op|'['
name|'attribute'
op|']'
op|'.'
name|'nodeValue'
op|','
name|'None'
op|')'
newline|'\n'
dedent|''
name|'return'
op|'('
name|'None'
op|','
name|'None'
op|')'
newline|'\n'
dedent|''
name|'try'
op|':'
newline|'\n'
indent|'        '
name|'return'
op|'('
name|'elt'
op|'.'
name|'firstChild'
op|'.'
name|'nodeValue'
op|','
name|'None'
op|')'
newline|'\n'
dedent|''
name|'except'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
dedent|''
name|'return'
op|'('
name|'None'
op|','
name|'None'
op|')'
newline|'\n'
nl|'\n'
DECL|function|findAlias
dedent|''
name|'def'
name|'findAlias'
op|'('
name|'file'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'doc'
op|'='
name|'False'
newline|'\n'
name|'if'
name|'doc_cache'
op|'.'
name|'has_key'
op|'('
name|'file'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'doc'
op|'='
name|'doc_cache'
op|'['
name|'file'
op|']'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'        '
name|'doc'
op|'='
name|'xml'
op|'.'
name|'dom'
op|'.'
name|'minidom'
op|'.'
name|'parse'
op|'('
name|'file'
op|')'
newline|'\n'
name|'doc_cache'
op|'['
name|'file'
op|']'
op|'='
name|'doc'
newline|'\n'
nl|'\n'
dedent|''
name|'alias_elt'
op|'='
name|'findChild'
op|'('
name|'doc'
op|'.'
name|'documentElement'
op|','
string|'"alias"'
op|')'
newline|'\n'
name|'if'
name|'not'
name|'alias_elt'
op|':'
newline|'\n'
indent|'        '
name|'return'
name|'False'
newline|'\n'
dedent|''
name|'if'
name|'not'
name|'alias_elt'
op|'.'
name|'attributes'
op|'.'
name|'has_key'
op|'('
string|"'source'"
op|')'
op|':'
newline|'\n'
indent|'        '
name|'return'
name|'False'
newline|'\n'
dedent|''
name|'return'
name|'alias_elt'
op|'.'
name|'attributes'
op|'['
string|"'source'"
op|']'
op|'.'
name|'nodeValue'
newline|'\n'
nl|'\n'
DECL|variable|parent_locales
dedent|''
name|'parent_locales'
op|'='
op|'{'
op|'}'
newline|'\n'
DECL|function|_fixedLookupChain
name|'def'
name|'_fixedLookupChain'
op|'('
name|'dirname'
op|','
name|'name'
op|')'
op|':'
newline|'\n'
comment|'# see http://www.unicode.org/reports/tr35/#Parent_Locales'
nl|'\n'
indent|'    '
name|'if'
name|'not'
name|'parent_locales'
op|':'
newline|'\n'
indent|'        '
name|'for'
name|'ns'
name|'in'
name|'findTagsInFile'
op|'('
name|'dirname'
op|'+'
string|'"/../supplemental/supplementalData.xml"'
op|','
string|'"parentLocales"'
op|')'
op|':'
newline|'\n'
indent|'            '
name|'tmp'
op|'='
op|'{'
op|'}'
newline|'\n'
name|'parent_locale'
op|'='
string|'""'
newline|'\n'
name|'for'
name|'data'
name|'in'
name|'ns'
op|'['
number|'1'
op|':'
op|']'
op|'['
number|'0'
op|']'
op|':'
comment|"# ns looks like this: [u'parentLocale', [(u'parent', u'root'), (u'locales', u'az_Cyrl bs_Cyrl en_Dsrt ..')]]"
newline|'\n'
indent|'                '
name|'tmp'
op|'['
name|'data'
op|'['
number|'0'
op|']'
op|']'
op|'='
name|'data'
op|'['
number|'1'
op|']'
newline|'\n'
name|'if'
name|'data'
op|'['
number|'0'
op|']'
op|'=='
string|'u"parent"'
op|':'
newline|'\n'
indent|'                    '
name|'parent_locale'
op|'='
name|'data'
op|'['
number|'1'
op|']'
newline|'\n'
dedent|''
dedent|''
name|'parent_locales'
op|'['
name|'parent_locale'
op|']'
op|'='
name|'tmp'
op|'['
string|'u"locales"'
op|']'
op|'.'
name|'split'
op|'('
string|'" "'
op|')'
newline|'\n'
nl|'\n'
dedent|''
dedent|''
name|'items'
op|'='
name|'name'
op|'.'
name|'split'
op|'('
string|'"_"'
op|')'
newline|'\n'
comment|'# split locale name into items and iterate through them from back to front'
nl|'\n'
comment|'# example: az_Latn_AZ => [az_Latn_AZ, az_Latn, az]'
nl|'\n'
name|'items'
op|'='
name|'list'
op|'('
name|'reversed'
op|'('
name|'map'
op|'('
name|'lambda'
name|'x'
op|':'
string|'"_"'
op|'.'
name|'join'
op|'('
name|'items'
op|'['
op|':'
name|'x'
op|'+'
number|'1'
op|']'
op|')'
op|','
name|'range'
op|'('
name|'len'
op|'('
name|'items'
op|')'
op|')'
op|')'
op|')'
op|')'
newline|'\n'
nl|'\n'
name|'for'
name|'i'
name|'in'
name|'range'
op|'('
name|'len'
op|'('
name|'items'
op|')'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'item'
op|'='
name|'items'
op|'['
name|'i'
op|']'
newline|'\n'
name|'for'
name|'parent_locale'
name|'in'
name|'parent_locales'
op|'.'
name|'keys'
op|'('
op|')'
op|':'
newline|'\n'
indent|'            '
name|'for'
name|'locale'
name|'in'
name|'parent_locales'
op|'['
name|'parent_locale'
op|']'
op|':'
newline|'\n'
indent|'                '
name|'if'
name|'item'
op|'=='
name|'locale'
op|':'
newline|'\n'
indent|'                    '
name|'if'
name|'parent_locale'
op|'=='
string|'u"root"'
op|':'
newline|'\n'
indent|'                        '
name|'items'
op|'='
name|'items'
op|'['
op|':'
name|'i'
op|'+'
number|'1'
op|']'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'                        '
name|'items'
op|'='
name|'items'
op|'['
op|':'
name|'i'
op|'+'
number|'1'
op|']'
op|'+'
name|'parent_locale'
op|'.'
name|'split'
op|'('
op|')'
op|'+'
name|'items'
op|'['
name|'i'
op|'+'
number|'1'
op|':'
op|']'
newline|'\n'
dedent|''
name|'return'
name|'items'
newline|'\n'
dedent|''
dedent|''
dedent|''
dedent|''
name|'return'
name|'items'
newline|'\n'
nl|'\n'
DECL|function|_findEntry
dedent|''
name|'def'
name|'_findEntry'
op|'('
name|'base'
op|','
name|'path'
op|','
name|'draft'
op|'='
name|'None'
op|','
name|'attribute'
op|'='
name|'None'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'file'
op|'='
name|'base'
newline|'\n'
name|'if'
name|'base'
op|'.'
name|'endswith'
op|'('
string|'".xml"'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'filename'
op|'='
name|'base'
newline|'\n'
name|'base'
op|'='
name|'base'
op|'['
op|':'
op|'-'
number|'4'
op|']'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'        '
name|'file'
op|'='
name|'base'
op|'+'
string|'".xml"'
newline|'\n'
dedent|''
op|'('
name|'dirname'
op|','
name|'filename'
op|')'
op|'='
name|'os'
op|'.'
name|'path'
op|'.'
name|'split'
op|'('
name|'base'
op|')'
newline|'\n'
nl|'\n'
name|'items'
op|'='
name|'_fixedLookupChain'
op|'('
name|'dirname'
op|','
name|'filename'
op|')'
newline|'\n'
name|'for'
name|'item'
name|'in'
name|'items'
op|':'
newline|'\n'
indent|'        '
name|'file'
op|'='
name|'dirname'
op|'+'
string|'"/"'
op|'+'
name|'item'
op|'+'
string|'".xml"'
newline|'\n'
name|'if'
name|'os'
op|'.'
name|'path'
op|'.'
name|'isfile'
op|'('
name|'file'
op|')'
op|':'
newline|'\n'
indent|'            '
name|'alias'
op|'='
name|'findAlias'
op|'('
name|'file'
op|')'
newline|'\n'
name|'if'
name|'alias'
op|':'
newline|'\n'
comment|'# if alias is found we should follow it and stop processing current file'
nl|'\n'
comment|'# see http://www.unicode.org/reports/tr35/#Common_Elements'
nl|'\n'
indent|'                '
name|'aliasfile'
op|'='
name|'os'
op|'.'
name|'path'
op|'.'
name|'dirname'
op|'('
name|'file'
op|')'
op|'+'
string|'"/"'
op|'+'
name|'alias'
op|'+'
string|'".xml"'
newline|'\n'
name|'if'
name|'not'
name|'os'
op|'.'
name|'path'
op|'.'
name|'isfile'
op|'('
name|'aliasfile'
op|')'
op|':'
newline|'\n'
indent|'                    '
name|'raise'
name|'Error'
op|'('
string|'"findEntry: fatal error: found an alias \'%s\' to \'%s\', but the alias file couldnt be found"'
op|'%'
op|'('
name|'filename'
op|','
name|'alias'
op|')'
op|')'
newline|'\n'
comment|'# found an alias, recurse into parsing it'
nl|'\n'
dedent|''
name|'result'
op|'='
name|'_findEntry'
op|'('
name|'aliasfile'
op|','
name|'path'
op|','
name|'draft'
op|','
name|'attribute'
op|')'
newline|'\n'
name|'return'
name|'result'
newline|'\n'
dedent|''
op|'('
name|'result'
op|','
name|'aliaspath'
op|')'
op|'='
name|'_findEntryInFile'
op|'('
name|'file'
op|','
name|'path'
op|','
name|'draft'
op|','
name|'attribute'
op|')'
newline|'\n'
name|'if'
name|'aliaspath'
op|':'
newline|'\n'
comment|'# start lookup again because of the alias source="locale"'
nl|'\n'
indent|'                '
name|'return'
name|'_findEntry'
op|'('
name|'base'
op|','
name|'aliaspath'
op|','
name|'draft'
op|','
name|'attribute'
op|')'
newline|'\n'
dedent|''
name|'if'
name|'result'
op|':'
newline|'\n'
indent|'                '
name|'return'
name|'result'
newline|'\n'
dedent|''
dedent|''
dedent|''
name|'return'
name|'None'
newline|'\n'
nl|'\n'
DECL|function|findEntry
dedent|''
name|'def'
name|'findEntry'
op|'('
name|'base'
op|','
name|'path'
op|','
name|'draft'
op|'='
name|'None'
op|','
name|'attribute'
op|'='
name|'None'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'file'
op|'='
name|'base'
newline|'\n'
name|'if'
name|'base'
op|'.'
name|'endswith'
op|'('
string|'".xml"'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'file'
op|'='
name|'base'
newline|'\n'
name|'base'
op|'='
name|'base'
op|'['
op|':'
op|'-'
number|'4'
op|']'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'        '
name|'file'
op|'='
name|'base'
op|'+'
string|'".xml"'
newline|'\n'
dedent|''
op|'('
name|'dirname'
op|','
name|'filename'
op|')'
op|'='
name|'os'
op|'.'
name|'path'
op|'.'
name|'split'
op|'('
name|'base'
op|')'
newline|'\n'
nl|'\n'
name|'result'
op|'='
name|'None'
newline|'\n'
name|'while'
name|'path'
op|':'
newline|'\n'
indent|'        '
name|'result'
op|'='
name|'_findEntry'
op|'('
name|'base'
op|','
name|'path'
op|','
name|'draft'
op|','
name|'attribute'
op|')'
newline|'\n'
name|'if'
name|'result'
op|':'
newline|'\n'
indent|'            '
name|'return'
name|'result'
newline|'\n'
dedent|''
op|'('
name|'result'
op|','
name|'aliaspath'
op|')'
op|'='
name|'_findEntryInFile'
op|'('
name|'dirname'
op|'+'
string|'"/root.xml"'
op|','
name|'path'
op|','
name|'draft'
op|','
name|'attribute'
op|')'
newline|'\n'
name|'if'
name|'result'
op|':'
newline|'\n'
indent|'            '
name|'return'
name|'result'
newline|'\n'
dedent|''
name|'if'
name|'not'
name|'aliaspath'
op|':'
newline|'\n'
indent|'            '
name|'raise'
name|'Error'
op|'('
string|'"findEntry: fatal error: %s: can not find key %s"'
op|'%'
op|'('
name|'filename'
op|','
name|'path'
op|')'
op|')'
newline|'\n'
dedent|''
name|'path'
op|'='
name|'aliaspath'
newline|'\n'
nl|'\n'
dedent|''
name|'return'
name|'result'
newline|'\n'
nl|'\n'
dedent|''
endmarker|''
end_unit
