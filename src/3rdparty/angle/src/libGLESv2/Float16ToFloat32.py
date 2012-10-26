begin_unit
comment|'# Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.'
nl|'\n'
comment|'# Use of this source code is governed by a BSD-style license that can be'
nl|'\n'
comment|'# found in the LICENSE file.'
nl|'\n'
comment|'#'
nl|'\n'
nl|'\n'
comment|'# This script generates a function that converts 16-bit precision floating'
nl|'\n'
comment|'# point numbers to 32-bit.'
nl|'\n'
comment|'# It is based on ftp://ftp.fox-toolkit.org/pub/fasthalffloatconversion.pdf.'
nl|'\n'
nl|'\n'
DECL|function|convertMantissa
name|'def'
name|'convertMantissa'
op|'('
name|'i'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'if'
name|'i'
op|'=='
number|'0'
op|':'
newline|'\n'
indent|'        '
name|'return'
number|'0'
newline|'\n'
dedent|''
name|'elif'
name|'i'
op|'<'
number|'1024'
op|':'
newline|'\n'
indent|'        '
name|'m'
op|'='
name|'i'
op|'<<'
number|'13'
newline|'\n'
name|'e'
op|'='
number|'0'
newline|'\n'
name|'while'
name|'not'
op|'('
name|'m'
op|'&'
number|'0x00800000'
op|')'
op|':'
newline|'\n'
indent|'            '
name|'e'
op|'-='
number|'0x00800000'
newline|'\n'
name|'m'
op|'='
name|'m'
op|'<<'
number|'1'
newline|'\n'
dedent|''
name|'m'
op|'&='
op|'~'
number|'0x00800000'
newline|'\n'
name|'e'
op|'+='
number|'0x38800000'
newline|'\n'
name|'return'
name|'m'
op|'|'
name|'e'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'        '
name|'return'
number|'0x38000000'
op|'+'
op|'('
op|'('
name|'i'
op|'-'
number|'1024'
op|')'
op|'<<'
number|'13'
op|')'
newline|'\n'
nl|'\n'
DECL|function|convertExponent
dedent|''
dedent|''
name|'def'
name|'convertExponent'
op|'('
name|'i'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'if'
name|'i'
op|'=='
number|'0'
op|':'
newline|'\n'
indent|'        '
name|'return'
number|'0'
newline|'\n'
dedent|''
name|'elif'
name|'i'
name|'in'
name|'range'
op|'('
number|'1'
op|','
number|'31'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'return'
name|'i'
op|'<<'
number|'23'
newline|'\n'
dedent|''
name|'elif'
name|'i'
op|'=='
number|'31'
op|':'
newline|'\n'
indent|'        '
name|'return'
number|'0x47800000'
newline|'\n'
dedent|''
name|'elif'
name|'i'
op|'=='
number|'32'
op|':'
newline|'\n'
indent|'        '
name|'return'
number|'0x80000000'
newline|'\n'
dedent|''
name|'elif'
name|'i'
name|'in'
name|'range'
op|'('
number|'33'
op|','
number|'63'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'return'
number|'0x80000000'
op|'+'
op|'('
op|'('
name|'i'
op|'-'
number|'32'
op|')'
op|'<<'
number|'23'
op|')'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'        '
name|'return'
number|'0xC7800000'
newline|'\n'
nl|'\n'
DECL|function|convertOffset
dedent|''
dedent|''
name|'def'
name|'convertOffset'
op|'('
name|'i'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'if'
name|'i'
op|'=='
number|'0'
name|'or'
name|'i'
op|'=='
number|'32'
op|':'
newline|'\n'
indent|'        '
name|'return'
number|'0'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'        '
name|'return'
number|'1024'
newline|'\n'
nl|'\n'
dedent|''
dedent|''
name|'print'
string|'"""//\n// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.\n// Use of this source code is governed by a BSD-style license that can be\n// found in the LICENSE file.\n//\n\n// This file is automatically generated.\n\nnamespace gl\n{\n"""'
newline|'\n'
nl|'\n'
name|'print'
string|'"const static unsigned g_mantissa[2048] = {"'
newline|'\n'
name|'for'
name|'i'
name|'in'
name|'range'
op|'('
number|'0'
op|','
number|'2048'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'print'
string|'"    %08x,"'
op|'%'
name|'convertMantissa'
op|'('
name|'i'
op|')'
newline|'\n'
dedent|''
name|'print'
string|'"};\\n"'
newline|'\n'
nl|'\n'
name|'print'
string|'"const static unsigned g_exponent[64] = {"'
newline|'\n'
name|'for'
name|'i'
name|'in'
name|'range'
op|'('
number|'0'
op|','
number|'64'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'print'
string|'"    %08x,"'
op|'%'
name|'convertExponent'
op|'('
name|'i'
op|')'
newline|'\n'
dedent|''
name|'print'
string|'"};\\n"'
newline|'\n'
nl|'\n'
name|'print'
string|'"const static unsigned g_offset[64] = {"'
newline|'\n'
name|'for'
name|'i'
name|'in'
name|'range'
op|'('
number|'0'
op|','
number|'64'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'print'
string|'"    %08x,"'
op|'%'
name|'convertOffset'
op|'('
name|'i'
op|')'
newline|'\n'
dedent|''
name|'print'
string|'"};\\n"'
newline|'\n'
nl|'\n'
name|'print'
string|'"""float float16ToFloat32(unsigned short h)\n{\n    unsigned i32 = =g_mantissa[g_offset[h >> 10] + (h & 0x3ff)] + g_exponent[h >> 10];\n    return *(float*) &i32;\n}\n}\n"""'
newline|'\n'
endmarker|''
end_unit
