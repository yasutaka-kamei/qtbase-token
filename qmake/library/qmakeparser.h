begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMAKEPARSER_H
end_ifndef
begin_define
DECL|macro|QMAKEPARSER_H
define|#
directive|define
name|QMAKEPARSER_H
end_define
begin_include
include|#
directive|include
file|"qmake_global.h"
end_include
begin_include
include|#
directive|include
file|"proitems.h"
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<qstack.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|PROPARSER_THREAD_SAFE
end_ifdef
begin_include
include|#
directive|include
file|<qmutex.h>
end_include
begin_include
include|#
directive|include
file|<qwaitcondition.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QMAKE_EXPORT
name|QMakeParserHandler
block|{
name|public
label|:
enum|enum
block|{
name|CategoryMask
init|=
literal|0xf00
block|,
name|WarningMessage
init|=
literal|0x000
block|,
name|ErrorMessage
init|=
literal|0x100
block|,
name|SourceMask
init|=
literal|0xf0
block|,
name|SourceParser
init|=
literal|0
block|,
name|CodeMask
init|=
literal|0xf
block|,
name|WarnLanguage
init|=
literal|0
block|,
name|WarnDeprecated
block|,
name|ParserWarnLanguage
init|=
name|SourceParser
operator||
name|WarningMessage
operator||
name|WarnLanguage
block|,
name|ParserWarnDeprecated
init|=
name|SourceParser
operator||
name|WarningMessage
operator||
name|WarnDeprecated
block|,
name|ParserIoError
init|=
name|ErrorMessage
operator||
name|SourceParser
block|,
name|ParserError
block|}
enum|;
name|virtual
name|void
name|message
parameter_list|(
name|int
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|msg
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
init|=
name|QString
argument_list|()
parameter_list|,
name|int
name|lineNo
init|=
literal|0
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|ProFileCache
name|class
name|ProFileCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMakeVfs
name|class
name|QMakeVfs
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QMAKE_EXPORT
name|QMakeParser
block|{
name|public
label|:
comment|// Call this from a concurrency-free context
specifier|static
name|void
name|initialize
parameter_list|()
function_decl|;
enum|enum
name|ParseFlag
block|{
name|ParseDefault
init|=
literal|0
block|,
name|ParseUseCache
init|=
literal|1
block|,
name|ParseReportMissing
init|=
literal|2
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|ParseFlags
argument_list|,
argument|ParseFlag
argument_list|)
name|QMakeParser
argument_list|(
name|ProFileCache
operator|*
name|cache
argument_list|,
name|QMakeVfs
operator|*
name|vfs
argument_list|,
name|QMakeParserHandler
operator|*
name|handler
argument_list|)
expr_stmt|;
enum|enum
name|SubGrammar
block|{
name|FullGrammar
block|,
name|TestGrammar
block|,
name|ValueGrammar
block|}
enum|;
comment|// fileName is expected to be absolute and cleanPath()ed.
name|ProFile
modifier|*
name|parsedProFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|ParseFlags
name|flags
init|=
name|ParseDefault
parameter_list|)
function_decl|;
name|ProFile
modifier|*
name|parsedProBlock
parameter_list|(
specifier|const
name|QString
modifier|&
name|contents
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|int
name|line
init|=
literal|0
parameter_list|,
name|SubGrammar
name|grammar
init|=
name|FullGrammar
parameter_list|)
function_decl|;
name|void
name|discardFileFromCache
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
name|private
label|:
enum|enum
name|ScopeNesting
block|{
name|NestNone
init|=
literal|0
block|,
name|NestLoop
init|=
literal|1
block|,
name|NestFunction
init|=
literal|2
block|}
enum|;
struct|struct
name|BlockScope
block|{
name|BlockScope
argument_list|()
operator|:
name|start
argument_list|(
literal|0
argument_list|)
operator|,
name|braceLevel
argument_list|(
literal|0
argument_list|)
operator|,
name|special
argument_list|(
name|false
argument_list|)
operator|,
name|inBranch
argument_list|(
name|false
argument_list|)
operator|,
name|nest
argument_list|(
argument|NestNone
argument_list|)
block|{}
name|BlockScope
argument_list|(
argument|const BlockScope&other
argument_list|)
block|{
operator|*
name|this
operator|=
name|other
block|; }
name|ushort
operator|*
name|start
expr_stmt|;
comment|// Where this block started; store length here
name|int
name|braceLevel
decl_stmt|;
comment|// Nesting of braces in scope
name|bool
name|special
decl_stmt|;
comment|// Single-line conditionals inside loops, etc. cannot have else branches
name|bool
name|inBranch
decl_stmt|;
comment|// The 'else' branch of the previous TokBranch is still open
name|uchar
name|nest
decl_stmt|;
comment|// Into what control structures we are nested
block|}
struct|;
enum|enum
name|ScopeState
block|{
name|StNew
block|,
comment|// Fresh scope
name|StCtrl
block|,
comment|// Control statement (for or else) met on current line
name|StCond
comment|// Conditionals met on current line
block|}
enum|;
enum|enum
name|Context
block|{
name|CtxTest
block|,
name|CtxValue
block|,
name|CtxPureValue
block|,
name|CtxArgs
block|}
enum|;
struct|struct
name|ParseCtx
block|{
name|int
name|parens
decl_stmt|;
comment|// Nesting of non-functional parentheses
name|int
name|argc
decl_stmt|;
comment|// Number of arguments in current function call
name|int
name|wordCount
decl_stmt|;
comment|// Number of words in current expression
name|Context
name|context
decl_stmt|;
name|ushort
name|quote
decl_stmt|;
comment|// Enclosing quote type
name|ushort
name|terminator
decl_stmt|;
comment|// '}' if replace function call is braced, ':' if test function
block|}
struct|;
name|bool
name|read
parameter_list|(
name|ProFile
modifier|*
name|pro
parameter_list|,
name|ParseFlags
name|flags
parameter_list|)
function_decl|;
name|void
name|read
parameter_list|(
name|ProFile
modifier|*
name|pro
parameter_list|,
specifier|const
name|QString
modifier|&
name|content
parameter_list|,
name|int
name|line
parameter_list|,
name|SubGrammar
name|grammar
parameter_list|)
function_decl|;
name|ALWAYS_INLINE
name|void
name|putTok
parameter_list|(
name|ushort
modifier|*
modifier|&
name|tokPtr
parameter_list|,
name|ushort
name|tok
parameter_list|)
function_decl|;
name|ALWAYS_INLINE
name|void
name|putBlockLen
parameter_list|(
name|ushort
modifier|*
modifier|&
name|tokPtr
parameter_list|,
name|uint
name|len
parameter_list|)
function_decl|;
name|ALWAYS_INLINE
name|void
name|putBlock
parameter_list|(
name|ushort
modifier|*
modifier|&
name|tokPtr
parameter_list|,
specifier|const
name|ushort
modifier|*
name|buf
parameter_list|,
name|uint
name|len
parameter_list|)
function_decl|;
name|void
name|putHashStr
parameter_list|(
name|ushort
modifier|*
modifier|&
name|pTokPtr
parameter_list|,
specifier|const
name|ushort
modifier|*
name|buf
parameter_list|,
name|uint
name|len
parameter_list|)
function_decl|;
name|void
name|finalizeHashStr
parameter_list|(
name|ushort
modifier|*
name|buf
parameter_list|,
name|uint
name|len
parameter_list|)
function_decl|;
name|void
name|putLineMarker
parameter_list|(
name|ushort
modifier|*
modifier|&
name|tokPtr
parameter_list|)
function_decl|;
name|ALWAYS_INLINE
name|bool
name|resolveVariable
parameter_list|(
name|ushort
modifier|*
name|xprPtr
parameter_list|,
name|int
name|tlen
parameter_list|,
name|int
name|needSep
parameter_list|,
name|ushort
modifier|*
modifier|*
name|ptr
parameter_list|,
name|ushort
modifier|*
modifier|*
name|buf
parameter_list|,
name|QString
modifier|*
name|xprBuff
parameter_list|,
name|ushort
modifier|*
modifier|*
name|tokPtr
parameter_list|,
name|QString
modifier|*
name|tokBuff
parameter_list|,
specifier|const
name|ushort
modifier|*
name|cur
parameter_list|,
specifier|const
name|QString
modifier|&
name|in
parameter_list|)
function_decl|;
name|void
name|finalizeCond
parameter_list|(
name|ushort
modifier|*
modifier|&
name|tokPtr
parameter_list|,
name|ushort
modifier|*
name|uc
parameter_list|,
name|ushort
modifier|*
name|ptr
parameter_list|,
name|int
name|wordCount
parameter_list|)
function_decl|;
name|void
name|finalizeCall
parameter_list|(
name|ushort
modifier|*
modifier|&
name|tokPtr
parameter_list|,
name|ushort
modifier|*
name|uc
parameter_list|,
name|ushort
modifier|*
name|ptr
parameter_list|,
name|int
name|argc
parameter_list|)
function_decl|;
name|void
name|warnOperator
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
name|bool
name|failOperator
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
name|bool
name|acceptColon
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
name|void
name|putOperator
parameter_list|(
name|ushort
modifier|*
modifier|&
name|tokPtr
parameter_list|)
function_decl|;
name|void
name|finalizeTest
parameter_list|(
name|ushort
modifier|*
modifier|&
name|tokPtr
parameter_list|)
function_decl|;
name|void
name|bogusTest
parameter_list|(
name|ushort
modifier|*
modifier|&
name|tokPtr
parameter_list|,
specifier|const
name|QString
modifier|&
name|msg
parameter_list|)
function_decl|;
name|void
name|enterScope
parameter_list|(
name|ushort
modifier|*
modifier|&
name|tokPtr
parameter_list|,
name|bool
name|special
parameter_list|,
name|ScopeState
name|state
parameter_list|)
function_decl|;
name|void
name|leaveScope
parameter_list|(
name|ushort
modifier|*
modifier|&
name|tokPtr
parameter_list|)
function_decl|;
name|void
name|flushCond
parameter_list|(
name|ushort
modifier|*
modifier|&
name|tokPtr
parameter_list|)
function_decl|;
name|void
name|flushScopes
parameter_list|(
name|ushort
modifier|*
modifier|&
name|tokPtr
parameter_list|)
function_decl|;
name|void
name|message
argument_list|(
name|int
name|type
argument_list|,
specifier|const
name|QString
operator|&
name|msg
argument_list|)
decl|const
decl_stmt|;
name|void
name|parseError
argument_list|(
specifier|const
name|QString
operator|&
name|msg
argument_list|)
decl|const
block|{
name|message
argument_list|(
name|QMakeParserHandler
operator|::
name|ParserError
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|m_proFile
operator|->
name|setOk
argument_list|(
name|false
argument_list|)
expr_stmt|;
block|}
name|void
name|languageWarning
argument_list|(
specifier|const
name|QString
operator|&
name|msg
argument_list|)
decl|const
block|{
name|message
argument_list|(
name|QMakeParserHandler
operator|::
name|ParserWarnLanguage
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
name|void
name|deprecationWarning
argument_list|(
specifier|const
name|QString
operator|&
name|msg
argument_list|)
decl|const
block|{
name|message
argument_list|(
name|QMakeParserHandler
operator|::
name|ParserWarnDeprecated
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
comment|// Current location
name|ProFile
modifier|*
name|m_proFile
decl_stmt|;
name|int
name|m_lineNo
decl_stmt|;
name|QStack
operator|<
name|BlockScope
operator|>
name|m_blockstack
expr_stmt|;
name|ScopeState
name|m_state
decl_stmt|;
name|int
name|m_markLine
decl_stmt|;
comment|// Put marker for this line
name|bool
name|m_inError
decl_stmt|;
comment|// Current line had a parsing error; suppress followup error messages
name|bool
name|m_canElse
decl_stmt|;
comment|// Conditionals met on previous line, but no scope was opened
name|int
name|m_invert
decl_stmt|;
comment|// Pending conditional is negated
enum|enum
block|{
name|NoOperator
block|,
name|AndOperator
block|,
name|OrOperator
block|}
name|m_operator
enum|;
comment|// Pending conditional is ORed/ANDed
name|QString
name|m_tmp
decl_stmt|;
comment|// Temporary for efficient toQString
name|ProFileCache
modifier|*
name|m_cache
decl_stmt|;
name|QMakeParserHandler
modifier|*
name|m_handler
decl_stmt|;
name|QMakeVfs
modifier|*
name|m_vfs
decl_stmt|;
comment|// This doesn't help gcc 3.3 ...
name|template
operator|<
name|typename
name|T
operator|>
name|friend
name|class
name|QTypeInfo
expr_stmt|;
name|friend
name|class
name|ProFileCache
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QMakeParser::ParseFlags
argument_list|)
end_macro
begin_decl_stmt
name|class
name|QMAKE_EXPORT
name|ProFileCache
block|{
name|public
label|:
name|ProFileCache
argument_list|()
block|{}
operator|~
name|ProFileCache
argument_list|()
expr_stmt|;
name|void
name|discardFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
name|void
name|discardFiles
parameter_list|(
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|)
function_decl|;
name|private
label|:
struct|struct
name|Entry
block|{
name|ProFile
modifier|*
name|pro
decl_stmt|;
ifdef|#
directive|ifdef
name|PROPARSER_THREAD_SAFE
struct|struct
name|Locker
block|{
name|Locker
argument_list|()
operator|:
name|waiters
argument_list|(
literal|0
argument_list|)
operator|,
name|done
argument_list|(
argument|false
argument_list|)
block|{}
name|QWaitCondition
name|cond
expr_stmt|;
name|int
name|waiters
decl_stmt|;
name|bool
name|done
decl_stmt|;
block|}
struct|;
name|Locker
modifier|*
name|locker
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
name|QHash
operator|<
name|QString
operator|,
name|Entry
operator|>
name|parsed_files
expr_stmt|;
ifdef|#
directive|ifdef
name|PROPARSER_THREAD_SAFE
name|QMutex
name|mutex
decl_stmt|;
endif|#
directive|endif
name|friend
name|class
name|QMakeParser
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|__GNUC__
operator|>
literal|3
operator|||
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|>
literal|3
operator|)
end_if
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QMakeParser
operator|::
name|BlockScope
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QMakeParser
operator|::
name|Context
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PROFILEPARSER_H
end_comment
end_unit
