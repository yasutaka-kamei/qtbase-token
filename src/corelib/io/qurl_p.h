begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Copyright (C) 2012 Intel Corporation. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QURL_P_H
end_ifndef
begin_define
DECL|macro|QURL_P_H
define|#
directive|define
name|QURL_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API. It exists for the convenience of
end_comment
begin_comment
comment|// qurl*.cpp This header file may change from version to version without
end_comment
begin_comment
comment|// notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"qurl.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QUrlPrivate
block|{
name|public
label|:
enum|enum
name|Section
block|{
name|Scheme
init|=
literal|0x01
block|,
name|UserName
init|=
literal|0x02
block|,
name|Password
init|=
literal|0x04
block|,
name|UserInfo
init|=
name|UserName
operator||
name|Password
block|,
name|Host
init|=
literal|0x08
block|,
name|Port
init|=
literal|0x10
block|,
name|Authority
init|=
name|UserInfo
operator||
name|Host
operator||
name|Port
block|,
name|Path
init|=
literal|0x20
block|,
name|Hierarchy
init|=
name|Authority
operator||
name|Path
block|,
name|Query
init|=
literal|0x40
block|,
name|Fragment
init|=
literal|0x80
block|,
name|FullUrl
init|=
literal|0xff
block|}
enum|;
enum|enum
name|ErrorCode
block|{
comment|// the high byte of the error code matches the Section
name|InvalidSchemeError
init|=
name|Scheme
operator|<<
literal|8
block|,
name|SchemeEmptyError
block|,
name|InvalidUserNameError
init|=
name|UserName
operator|<<
literal|8
block|,
name|InvalidPasswordError
init|=
name|Password
operator|<<
literal|8
block|,
name|InvalidRegNameError
init|=
name|Host
operator|<<
literal|8
block|,
name|InvalidIPv4AddressError
block|,
name|InvalidIPv6AddressError
block|,
name|InvalidIPvFutureError
block|,
name|HostMissingEndBracket
block|,
name|InvalidPortError
init|=
name|Port
operator|<<
literal|8
block|,
name|PortEmptyError
block|,
name|InvalidPathError
init|=
name|Path
operator|<<
literal|8
block|,
name|PathContainsColonBeforeSlash
block|,
name|InvalidQueryError
init|=
name|Query
operator|<<
literal|8
block|,
name|InvalidFragmentError
init|=
name|Fragment
operator|<<
literal|8
block|,
name|NoError
init|=
literal|0
block|}
enum|;
name|QUrlPrivate
argument_list|()
expr_stmt|;
name|QUrlPrivate
argument_list|(
specifier|const
name|QUrlPrivate
operator|&
name|copy
argument_list|)
expr_stmt|;
name|void
name|parse
argument_list|(
specifier|const
name|QString
operator|&
name|url
argument_list|,
name|QUrl
operator|::
name|ParsingMode
name|parsingMode
argument_list|)
decl_stmt|;
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|sectionIsPresent
operator|==
literal|0
operator|&&
name|port
operator|==
operator|-
literal|1
operator|&&
name|path
operator|.
name|isEmpty
argument_list|()
return|;
block|}
comment|// no QString scheme() const;
name|void
name|appendAuthority
argument_list|(
name|QString
operator|&
name|appendTo
argument_list|,
name|QUrl
operator|::
name|FormattingOptions
name|options
argument_list|,
name|Section
name|appendingTo
argument_list|)
decl|const
decl_stmt|;
name|void
name|appendUserInfo
argument_list|(
name|QString
operator|&
name|appendTo
argument_list|,
name|QUrl
operator|::
name|FormattingOptions
name|options
argument_list|,
name|Section
name|appendingTo
argument_list|)
decl|const
decl_stmt|;
name|void
name|appendUserName
argument_list|(
name|QString
operator|&
name|appendTo
argument_list|,
name|QUrl
operator|::
name|FormattingOptions
name|options
argument_list|)
decl|const
decl_stmt|;
name|void
name|appendPassword
argument_list|(
name|QString
operator|&
name|appendTo
argument_list|,
name|QUrl
operator|::
name|FormattingOptions
name|options
argument_list|)
decl|const
decl_stmt|;
name|void
name|appendHost
argument_list|(
name|QString
operator|&
name|appendTo
argument_list|,
name|QUrl
operator|::
name|FormattingOptions
name|options
argument_list|)
decl|const
decl_stmt|;
name|void
name|appendPath
argument_list|(
name|QString
operator|&
name|appendTo
argument_list|,
name|QUrl
operator|::
name|FormattingOptions
name|options
argument_list|,
name|Section
name|appendingTo
argument_list|)
decl|const
decl_stmt|;
name|void
name|appendQuery
argument_list|(
name|QString
operator|&
name|appendTo
argument_list|,
name|QUrl
operator|::
name|FormattingOptions
name|options
argument_list|,
name|Section
name|appendingTo
argument_list|)
decl|const
decl_stmt|;
name|void
name|appendFragment
argument_list|(
name|QString
operator|&
name|appendTo
argument_list|,
name|QUrl
operator|::
name|FormattingOptions
name|options
argument_list|)
decl|const
decl_stmt|;
comment|// the "end" parameters are like STL iterators: they point to one past the last valid element
name|bool
name|setScheme
parameter_list|(
specifier|const
name|QString
modifier|&
name|value
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|bool
name|setAuthority
parameter_list|(
specifier|const
name|QString
modifier|&
name|auth
parameter_list|,
name|int
name|from
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
name|void
name|setUserInfo
parameter_list|(
specifier|const
name|QString
modifier|&
name|userInfo
parameter_list|,
name|int
name|from
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
name|void
name|setUserName
parameter_list|(
specifier|const
name|QString
modifier|&
name|value
parameter_list|,
name|int
name|from
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
name|void
name|setPassword
parameter_list|(
specifier|const
name|QString
modifier|&
name|value
parameter_list|,
name|int
name|from
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
name|bool
name|setHost
parameter_list|(
specifier|const
name|QString
modifier|&
name|value
parameter_list|,
name|int
name|from
parameter_list|,
name|int
name|end
parameter_list|,
name|bool
name|maybePercentEncoded
init|=
name|true
parameter_list|)
function_decl|;
name|void
name|setPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|value
parameter_list|,
name|int
name|from
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
name|void
name|setQuery
parameter_list|(
specifier|const
name|QString
modifier|&
name|value
parameter_list|,
name|int
name|from
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
name|void
name|setFragment
parameter_list|(
specifier|const
name|QString
modifier|&
name|value
parameter_list|,
name|int
name|from
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|hasScheme
argument_list|()
specifier|const
block|{
return|return
name|sectionIsPresent
operator|&
name|Scheme
return|;
block|}
specifier|inline
name|bool
name|hasAuthority
argument_list|()
specifier|const
block|{
return|return
name|sectionIsPresent
operator|&
name|Authority
return|;
block|}
specifier|inline
name|bool
name|hasUserInfo
argument_list|()
specifier|const
block|{
return|return
name|sectionIsPresent
operator|&
name|UserInfo
return|;
block|}
specifier|inline
name|bool
name|hasUserName
argument_list|()
specifier|const
block|{
return|return
name|sectionIsPresent
operator|&
name|UserName
return|;
block|}
specifier|inline
name|bool
name|hasPassword
argument_list|()
specifier|const
block|{
return|return
name|sectionIsPresent
operator|&
name|Password
return|;
block|}
specifier|inline
name|bool
name|hasHost
argument_list|()
specifier|const
block|{
return|return
name|sectionIsPresent
operator|&
name|Host
return|;
block|}
specifier|inline
name|bool
name|hasPort
argument_list|()
specifier|const
block|{
return|return
name|port
operator|!=
operator|-
literal|1
return|;
block|}
specifier|inline
name|bool
name|hasPath
argument_list|()
specifier|const
block|{
return|return
operator|!
name|path
operator|.
name|isEmpty
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|hasQuery
argument_list|()
specifier|const
block|{
return|return
name|sectionIsPresent
operator|&
name|Query
return|;
block|}
specifier|inline
name|bool
name|hasFragment
argument_list|()
specifier|const
block|{
return|return
name|sectionIsPresent
operator|&
name|Fragment
return|;
block|}
name|QString
name|mergePaths
argument_list|(
specifier|const
name|QString
operator|&
name|relativePath
argument_list|)
decl|const
decl_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
name|int
name|port
decl_stmt|;
name|QString
name|scheme
decl_stmt|;
name|QString
name|userName
decl_stmt|;
name|QString
name|password
decl_stmt|;
name|QString
name|host
decl_stmt|;
name|QString
name|path
decl_stmt|;
name|QString
name|query
decl_stmt|;
name|QString
name|fragment
decl_stmt|;
name|ushort
name|errorCode
decl_stmt|;
name|ushort
name|errorSupplement
decl_stmt|;
comment|// not used for:
comment|//  - Port (port == -1 means absence)
comment|//  - Path (there's no path delimiter, so we optimize its use out of existence)
comment|// Schemes are never supposed to be empty, but we keep the flag anyway
name|uchar
name|sectionIsPresent
decl_stmt|;
comment|// UserName, Password, Path, Query, and Fragment never contain errors in TolerantMode.
comment|// Those flags are set only by the strict parser.
name|uchar
name|sectionHasError
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// in qurlrecode.cpp
end_comment
begin_decl_stmt
specifier|extern
name|Q_AUTOTEST_EXPORT
name|int
name|qt_urlRecode
argument_list|(
name|QString
operator|&
name|appendTo
argument_list|,
specifier|const
name|QChar
operator|*
name|begin
argument_list|,
specifier|const
name|QChar
operator|*
name|end
argument_list|,
name|QUrl
operator|::
name|ComponentFormattingOptions
name|encoding
argument_list|,
specifier|const
name|ushort
operator|*
name|tableModifications
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// in qurlidna.cpp
end_comment
begin_enum
DECL|enum|AceOperation
DECL|enumerator|ToAceOnly
DECL|enumerator|NormalizeAce
enum|enum
name|AceOperation
block|{
name|ToAceOnly
block|,
name|NormalizeAce
block|}
enum|;
end_enum
begin_function_decl
specifier|extern
name|QString
name|qt_ACE_do
parameter_list|(
specifier|const
name|QString
modifier|&
name|domain
parameter_list|,
name|AceOperation
name|op
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|Q_AUTOTEST_EXPORT
name|void
name|qt_nameprep
parameter_list|(
name|QString
modifier|*
name|source
parameter_list|,
name|int
name|from
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|Q_AUTOTEST_EXPORT
name|bool
name|qt_check_std3rules
parameter_list|(
specifier|const
name|QChar
modifier|*
name|uc
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|Q_AUTOTEST_EXPORT
name|void
name|qt_punycodeEncoder
parameter_list|(
specifier|const
name|QChar
modifier|*
name|s
parameter_list|,
name|int
name|ucLength
parameter_list|,
name|QString
modifier|*
name|output
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|Q_AUTOTEST_EXPORT
name|QString
name|qt_punycodeDecoder
parameter_list|(
specifier|const
name|QString
modifier|&
name|pc
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QURL_P_H
end_comment
end_unit
