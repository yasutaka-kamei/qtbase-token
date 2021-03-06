begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSETTINGS_P_H
end_ifndef
begin_define
DECL|macro|QSETTINGS_P_H
define|#
directive|define
name|QSETTINGS_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|"QtCore/qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmap.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmutex.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qiodevice.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstack.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstringlist.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
end_ifndef
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"private/qscopedpointer_p.h"
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|Q_OS_WIN
DECL|macro|QT_QSETTINGS_ALWAYS_CASE_SENSITIVE_AND_FORGET_ORIGINAL_KEY_ORDER
define|#
directive|define
name|QT_QSETTINGS_ALWAYS_CASE_SENSITIVE_AND_FORGET_ORIGINAL_KEY_ORDER
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
DECL|macro|QT_QTSETTINGS_FORGET_ORIGINAL_KEY_ORDER
define|#
directive|define
name|QT_QTSETTINGS_FORGET_ORIGINAL_KEY_ORDER
endif|#
directive|endif
comment|// used in testing framework
DECL|macro|QSETTINGS_P_H_VERSION
define|#
directive|define
name|QSETTINGS_P_H_VERSION
value|3
ifdef|#
directive|ifdef
name|QT_QSETTINGS_ALWAYS_CASE_SENSITIVE_AND_FORGET_ORIGINAL_KEY_ORDER
DECL|variable|IniCaseSensitivity
specifier|static
specifier|const
name|Qt
operator|::
name|CaseSensitivity
name|IniCaseSensitivity
operator|=
name|Qt
operator|::
name|CaseSensitive
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QSettingsKey
range|:
name|public
name|QString
block|{
name|public
operator|:
specifier|inline
name|QSettingsKey
argument_list|(
argument|const QString&key
argument_list|,
argument|Qt::CaseSensitivity cs
argument_list|,
argument|int
comment|/* position */
argument|= -
literal|1
argument_list|)
operator|:
name|QString
argument_list|(
argument|key
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|cs
operator|==
name|Qt
operator|::
name|CaseSensitive
argument_list|)
block|;
name|Q_UNUSED
argument_list|(
name|cs
argument_list|)
block|; }
specifier|inline
name|QString
name|originalCaseKey
argument_list|()
specifier|const
block|{
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|int
name|originalKeyPosition
argument_list|()
specifier|const
block|{
return|return
operator|-
literal|1
return|;
block|}
expr|}
block|;
else|#
directive|else
specifier|static
specifier|const
name|Qt
operator|::
name|CaseSensitivity
name|IniCaseSensitivity
operator|=
name|Qt
operator|::
name|CaseInsensitive
block|;
name|class
name|QSettingsKey
operator|:
name|public
name|QString
block|{
name|public
operator|:
specifier|inline
name|QSettingsKey
argument_list|(
argument|const QString&key
argument_list|,
argument|Qt::CaseSensitivity cs
argument_list|,
argument|int position = -
literal|1
argument_list|)
operator|:
name|QString
argument_list|(
name|key
argument_list|)
block|,
name|theOriginalKey
argument_list|(
name|key
argument_list|)
block|,
name|theOriginalKeyPosition
argument_list|(
argument|position
argument_list|)
block|{
if|if
condition|(
name|cs
operator|==
name|Qt
operator|::
name|CaseInsensitive
condition|)
name|QString
operator|::
name|operator
operator|=
operator|(
name|toLower
argument_list|()
operator|)
expr_stmt|;
block|}
specifier|inline
name|QString
name|originalCaseKey
argument_list|()
specifier|const
block|{
return|return
name|theOriginalKey
return|;
block|}
specifier|inline
name|int
name|originalKeyPosition
argument_list|()
specifier|const
block|{
return|return
name|theOriginalKeyPosition
return|;
block|}
name|private
operator|:
name|QString
name|theOriginalKey
block|;
name|int
name|theOriginalKeyPosition
block|; }
block|;
endif|#
directive|endif
DECL|typedef|QSettingsKey
DECL|typedef|UnparsedSettingsMap
typedef|typedef
name|QMap
operator|<
name|QSettingsKey
operator|,
name|QByteArray
operator|>
name|UnparsedSettingsMap
expr_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|QSettingsKey
DECL|typedef|ParsedSettingsMap
typedef|typedef
name|QMap
operator|<
name|QSettingsKey
operator|,
name|QVariant
operator|>
name|ParsedSettingsMap
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QSettingsGroup
block|{
name|public
label|:
specifier|inline
name|QSettingsGroup
argument_list|()
operator|:
name|num
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|maxNum
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
specifier|inline
name|QSettingsGroup
argument_list|(
specifier|const
name|QString
operator|&
name|s
argument_list|)
operator|:
name|str
argument_list|(
name|s
argument_list|)
operator|,
name|num
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|maxNum
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
specifier|inline
name|QSettingsGroup
argument_list|(
argument|const QString&s
argument_list|,
argument|bool guessArraySize
argument_list|)
operator|:
name|str
argument_list|(
name|s
argument_list|)
operator|,
name|num
argument_list|(
literal|0
argument_list|)
operator|,
name|maxNum
argument_list|(
argument|guessArraySize ?
literal|0
argument|: -
literal|1
argument_list|)
block|{}
specifier|inline
name|QString
name|name
argument_list|()
specifier|const
block|{
return|return
name|str
return|;
block|}
specifier|inline
name|QString
name|toString
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|isArray
argument_list|()
specifier|const
block|{
return|return
name|num
operator|!=
operator|-
literal|1
return|;
block|}
specifier|inline
name|int
name|arraySizeGuess
argument_list|()
specifier|const
block|{
return|return
name|maxNum
return|;
block|}
specifier|inline
name|void
name|setArrayIndex
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|num
operator|=
name|i
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|maxNum
operator|!=
operator|-
literal|1
operator|&&
name|num
operator|>
name|maxNum
condition|)
name|maxNum
operator|=
name|num
expr_stmt|;
block|}
name|QString
name|str
decl_stmt|;
name|int
name|num
decl_stmt|;
name|int
name|maxNum
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QSettingsGroup
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|function|toString
specifier|inline
name|QString
name|QSettingsGroup
operator|::
name|toString
argument_list|()
specifier|const
block|{
name|QString
name|result
block|;
name|result
operator|=
name|str
block|;
if|if
condition|(
name|num
operator|>
literal|0
condition|)
block|{
name|result
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
expr_stmt|;
name|result
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|num
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|result
return|;
end_return
begin_decl_stmt
unit|}  class
name|Q_AUTOTEST_EXPORT
name|QConfFile
block|{
name|public
label|:
operator|~
name|QConfFile
argument_list|()
expr_stmt|;
name|ParsedSettingsMap
name|mergedKeyMap
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isWritable
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QConfFile
modifier|*
name|fromName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|bool
name|_userPerms
parameter_list|)
function_decl|;
specifier|static
name|void
name|clearCache
parameter_list|()
function_decl|;
name|QString
name|name
decl_stmt|;
name|QDateTime
name|timeStamp
decl_stmt|;
name|qint64
name|size
decl_stmt|;
name|UnparsedSettingsMap
name|unparsedIniSections
decl_stmt|;
name|ParsedSettingsMap
name|originalKeys
decl_stmt|;
name|ParsedSettingsMap
name|addedKeys
decl_stmt|;
name|ParsedSettingsMap
name|removedKeys
decl_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
name|QMutex
name|mutex
decl_stmt|;
name|bool
name|userPerms
decl_stmt|;
name|private
label|:
ifdef|#
directive|ifdef
name|Q_DISABLE_COPY
name|QConfFile
argument_list|(
specifier|const
name|QConfFile
operator|&
argument_list|)
expr_stmt|;
name|QConfFile
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QConfFile
operator|&
operator|)
decl_stmt|;
endif|#
directive|endif
name|QConfFile
argument_list|(
argument|const QString&name
argument_list|,
argument|bool _userPerms
argument_list|)
empty_stmt|;
name|friend
name|class
name|QConfFile_createsItself
decl_stmt|;
comment|// silences compiler warning
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QSettingsPrivate
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
range|:
name|public
name|QObjectPrivate
endif|#
directive|endif
block|{
ifdef|#
directive|ifdef
name|QT_NO_QOBJECT
name|QSettings
operator|*
name|q_ptr
block|;
endif|#
directive|endif
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QSettings
argument_list|)
name|public
operator|:
name|QSettingsPrivate
argument_list|(
argument|QSettings::Format format
argument_list|)
block|;
name|QSettingsPrivate
argument_list|(
argument|QSettings::Format format
argument_list|,
argument|QSettings::Scope scope
argument_list|,
argument|const QString&organization
argument_list|,
argument|const QString&application
argument_list|)
block|;
name|virtual
operator|~
name|QSettingsPrivate
argument_list|()
block|;
name|virtual
name|void
name|remove
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|set
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|get
argument_list|(
argument|const QString&key
argument_list|,
argument|QVariant *value
argument_list|)
specifier|const
operator|=
literal|0
block|;      enum
name|ChildSpec
block|{
name|AllKeys
block|,
name|ChildKeys
block|,
name|ChildGroups
block|}
block|;
name|virtual
name|QStringList
name|children
argument_list|(
argument|const QString&prefix
argument_list|,
argument|ChildSpec spec
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|clear
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|sync
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|flush
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|isWritable
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QString
name|fileName
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|QString
name|actualKey
argument_list|(
argument|const QString&key
argument_list|)
specifier|const
block|;
name|void
name|beginGroupOrArray
argument_list|(
specifier|const
name|QSettingsGroup
operator|&
name|group
argument_list|)
block|;
name|void
name|setStatus
argument_list|(
argument|QSettings::Status status
argument_list|)
specifier|const
block|;
name|void
name|requestUpdate
argument_list|()
block|;
name|void
name|update
argument_list|()
block|;
specifier|static
name|QString
name|normalizedKey
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
block|;
specifier|static
name|QSettingsPrivate
operator|*
name|create
argument_list|(
argument|QSettings::Format format
argument_list|,
argument|QSettings::Scope scope
argument_list|,
argument|const QString&organization
argument_list|,
argument|const QString&application
argument_list|)
block|;
specifier|static
name|QSettingsPrivate
operator|*
name|create
argument_list|(
argument|const QString&fileName
argument_list|,
argument|QSettings::Format format
argument_list|)
block|;
specifier|static
name|void
name|processChild
argument_list|(
argument|QStringRef key
argument_list|,
argument|ChildSpec spec
argument_list|,
argument|QStringList&result
argument_list|)
block|;
comment|// Variant streaming functions
specifier|static
name|QStringList
name|variantListToStringList
argument_list|(
specifier|const
name|QVariantList
operator|&
name|l
argument_list|)
block|;
specifier|static
name|QVariant
name|stringListToVariantList
argument_list|(
specifier|const
name|QStringList
operator|&
name|l
argument_list|)
block|;
comment|// parser functions
specifier|static
name|QString
name|variantToString
argument_list|(
specifier|const
name|QVariant
operator|&
name|v
argument_list|)
block|;
specifier|static
name|QVariant
name|stringToVariant
argument_list|(
specifier|const
name|QString
operator|&
name|s
argument_list|)
block|;
specifier|static
name|void
name|iniEscapedKey
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
name|QByteArray
operator|&
name|result
argument_list|)
block|;
specifier|static
name|bool
name|iniUnescapedKey
argument_list|(
argument|const QByteArray&key
argument_list|,
argument|int from
argument_list|,
argument|int to
argument_list|,
argument|QString&result
argument_list|)
block|;
specifier|static
name|void
name|iniEscapedString
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|,
name|QByteArray
operator|&
name|result
argument_list|,
name|QTextCodec
operator|*
name|codec
argument_list|)
block|;
specifier|static
name|void
name|iniEscapedStringList
argument_list|(
specifier|const
name|QStringList
operator|&
name|strs
argument_list|,
name|QByteArray
operator|&
name|result
argument_list|,
name|QTextCodec
operator|*
name|codec
argument_list|)
block|;
specifier|static
name|bool
name|iniUnescapedStringList
argument_list|(
argument|const QByteArray&str
argument_list|,
argument|int from
argument_list|,
argument|int to
argument_list|,
argument|QString&stringResult
argument_list|,
argument|QStringList&stringListResult
argument_list|,
argument|QTextCodec *codec
argument_list|)
block|;
specifier|static
name|QStringList
name|splitArgs
argument_list|(
argument|const QString&s
argument_list|,
argument|int idx
argument_list|)
block|;
comment|/*     The numeric values of these enums define their search order. For example,     F_User | F_Organization is searched before F_System | F_Application,     because their values are respectively 1 and 2.     */
block|enum
block|{
name|F_Application
operator|=
literal|0x0
block|,
name|F_Organization
operator|=
literal|0x1
block|,
name|F_User
operator|=
literal|0x0
block|,
name|F_System
operator|=
literal|0x2
block|,
name|NumConfFiles
operator|=
literal|4
block|}
block|;
name|QSettings
operator|::
name|Format
name|format
block|;
name|QSettings
operator|::
name|Scope
name|scope
block|;
name|QString
name|organizationName
block|;
name|QString
name|applicationName
block|;
name|QTextCodec
operator|*
name|iniCodec
block|;
name|protected
operator|:
name|QStack
operator|<
name|QSettingsGroup
operator|>
name|groupStack
block|;
name|QString
name|groupPrefix
block|;
name|int
name|spec
block|;
name|bool
name|fallbacks
block|;
name|bool
name|pendingChanges
block|;
name|mutable
name|QSettings
operator|::
name|Status
name|status
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QConfFileSettingsPrivate
range|:
name|public
name|QSettingsPrivate
block|{
name|public
operator|:
name|QConfFileSettingsPrivate
argument_list|(
argument|QSettings::Format format
argument_list|,
argument|QSettings::Scope scope
argument_list|,
argument|const QString&organization
argument_list|,
argument|const QString&application
argument_list|)
block|;
name|QConfFileSettingsPrivate
argument_list|(
argument|const QString&fileName
argument_list|,
argument|QSettings::Format format
argument_list|)
block|;
operator|~
name|QConfFileSettingsPrivate
argument_list|()
block|;
name|void
name|remove
argument_list|(
argument|const QString&key
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|set
argument_list|(
argument|const QString&key
argument_list|,
argument|const QVariant&value
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|get
argument_list|(
argument|const QString&key
argument_list|,
argument|QVariant *value
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QStringList
name|children
argument_list|(
argument|const QString&prefix
argument_list|,
argument|ChildSpec spec
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|clear
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|sync
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|flush
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isWritable
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|fileName
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|readIniFile
argument_list|(
specifier|const
name|QByteArray
operator|&
name|data
argument_list|,
name|UnparsedSettingsMap
operator|*
name|unparsedIniSections
argument_list|)
block|;
specifier|static
name|bool
name|readIniSection
argument_list|(
specifier|const
name|QSettingsKey
operator|&
name|section
argument_list|,
specifier|const
name|QByteArray
operator|&
name|data
argument_list|,
name|ParsedSettingsMap
operator|*
name|settingsMap
argument_list|,
name|QTextCodec
operator|*
name|codec
argument_list|)
block|;
specifier|static
name|bool
name|readIniLine
argument_list|(
specifier|const
name|QByteArray
operator|&
name|data
argument_list|,
name|int
operator|&
name|dataPos
argument_list|,
name|int
operator|&
name|lineStart
argument_list|,
name|int
operator|&
name|lineLen
argument_list|,
name|int
operator|&
name|equalsPos
argument_list|)
block|;
name|private
operator|:
name|void
name|initFormat
argument_list|()
block|;
name|void
name|initAccess
argument_list|()
block|;
name|void
name|syncConfFile
argument_list|(
argument|int confFileNo
argument_list|)
block|;
name|bool
name|writeIniFile
argument_list|(
name|QIODevice
operator|&
name|device
argument_list|,
specifier|const
name|ParsedSettingsMap
operator|&
name|map
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|bool
name|readPlistFile
argument_list|(
argument|const QString&fileName
argument_list|,
argument|ParsedSettingsMap *map
argument_list|)
specifier|const
block|;
name|bool
name|writePlistFile
argument_list|(
argument|const QString&fileName
argument_list|,
argument|const ParsedSettingsMap&map
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|void
name|ensureAllSectionsParsed
argument_list|(
argument|QConfFile *confFile
argument_list|)
specifier|const
block|;
name|void
name|ensureSectionParsed
argument_list|(
argument|QConfFile *confFile
argument_list|,
argument|const QSettingsKey&key
argument_list|)
specifier|const
block|;
name|QScopedSharedPointer
operator|<
name|QConfFile
operator|>
name|confFiles
index|[
name|NumConfFiles
index|]
block|;
name|QSettings
operator|::
name|ReadFunc
name|readFunc
block|;
name|QSettings
operator|::
name|WriteFunc
name|writeFunc
block|;
name|QString
name|extension
block|;
name|Qt
operator|::
name|CaseSensitivity
name|caseSensitivity
block|;
name|int
name|nextPosition
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSETTINGS_P_H
end_comment
end_unit
