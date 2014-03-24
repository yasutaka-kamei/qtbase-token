begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qloggingregistry_p.h"
end_include
begin_include
include|#
directive|include
file|"qloggingcategory_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qfile.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstandardpaths.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdir.h>
end_include
begin_comment
comment|// We can't use the default macros because this would lead to recursion.
end_comment
begin_comment
comment|// Instead let's define our own one that unconditionally logs...
end_comment
begin_define
DECL|macro|debugMsg
define|#
directive|define
name|debugMsg
value|QMessageLogger(__FILE__, __LINE__, __FUNCTION__, "qt.core.logging").debug
end_define
begin_define
DECL|macro|warnMsg
define|#
directive|define
name|warnMsg
value|QMessageLogger(__FILE__, __LINE__, __FUNCTION__, "qt.core.logging").warning
end_define
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_GLOBAL_STATIC
argument_list|(
name|QLoggingRegistry
argument_list|,
name|qtLoggingRegistry
argument_list|)
comment|/*!     \internal     Constructs a logging rule with default values. */
DECL|function|QLoggingRule
name|QLoggingRule
operator|::
name|QLoggingRule
argument_list|()
range|:
name|enabled
argument_list|(
literal|false
argument_list|)
block|{ }
comment|/*!     \internal     Constructs a logging rule. */
DECL|function|QLoggingRule
name|QLoggingRule
operator|::
name|QLoggingRule
operator|(
specifier|const
name|QStringRef
operator|&
name|pattern
expr|,
name|bool
name|enabled
operator|)
operator|:
name|messageType
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|,
name|enabled
argument_list|(
name|enabled
argument_list|)
argument_list|{
name|parse
argument_list|(
name|pattern
argument_list|)
argument_list|; }
comment|/*!     \internal     Return value 1 means filter passed, 0 means filter doesn't influence this     category, -1 means category doesn't pass this filter.  */
DECL|function|pass
name|int
name|QLoggingRule
operator|::
name|pass
argument_list|(
specifier|const
name|QString
operator|&
name|cat
argument_list|,
name|QtMsgType
name|msgType
argument_list|)
decl|const
argument_list|{
comment|// check message type
argument_list|if
operator|(
name|messageType
operator|>
operator|-
literal|1
operator|&&
name|messageType
operator|!=
name|msgType
operator|)
return|return
literal|0
return|;
end_decl_stmt
begin_if
if|if
condition|(
name|flags
operator|==
name|FullText
condition|)
block|{
comment|// full match
if|if
condition|(
name|category
operator|==
name|cat
condition|)
return|return
operator|(
name|enabled
condition|?
literal|1
else|:
operator|-
literal|1
operator|)
return|;
else|else
return|return
literal|0
return|;
block|}
end_if
begin_decl_stmt
specifier|const
name|int
name|idx
init|=
name|cat
operator|.
name|indexOf
argument_list|(
name|category
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|idx
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|flags
operator|==
name|MidFilter
condition|)
block|{
comment|// matches somewhere
if|if
condition|(
name|idx
operator|>=
literal|0
condition|)
return|return
operator|(
name|enabled
condition|?
literal|1
else|:
operator|-
literal|1
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|flags
operator|==
name|LeftFilter
condition|)
block|{
comment|// matches left
if|if
condition|(
name|idx
operator|==
literal|0
condition|)
return|return
operator|(
name|enabled
condition|?
literal|1
else|:
operator|-
literal|1
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|flags
operator|==
name|RightFilter
condition|)
block|{
comment|// matches right
if|if
condition|(
name|idx
operator|==
operator|(
name|cat
operator|.
name|count
argument_list|()
operator|-
name|category
operator|.
name|count
argument_list|()
operator|)
condition|)
return|return
operator|(
name|enabled
condition|?
literal|1
else|:
operator|-
literal|1
operator|)
return|;
block|}
block|}
end_if
begin_return
return|return
literal|0
return|;
end_return
begin_comment
unit|}
comment|/*!     \internal     Parses \a pattern.     Allowed is f.ex.:              qt.core.io.debug      FullText, QtDebugMsg              qt.core.*             LeftFilter, all types              *.io.warning          RightFilter, QtWarningMsg              *.core.*              MidFilter  */
end_comment
begin_macro
unit|void
DECL|function|parse
name|QLoggingRule
end_macro
begin_expr_stmt
DECL|function|parse
operator|::
name|parse
operator|(
specifier|const
name|QStringRef
operator|&
name|pattern
operator|)
block|{
name|QStringRef
name|p
block|;
comment|// strip trailing ".messagetype"
if|if
condition|(
name|pattern
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|".debug"
argument_list|)
argument_list|)
condition|)
block|{
name|p
operator|=
name|QStringRef
argument_list|(
name|pattern
operator|.
name|string
argument_list|()
argument_list|,
name|pattern
operator|.
name|position
argument_list|()
argument_list|,
name|pattern
operator|.
name|length
argument_list|()
operator|-
name|strlen
argument_list|(
literal|".debug"
argument_list|)
argument_list|)
expr_stmt|;
name|messageType
operator|=
name|QtDebugMsg
expr_stmt|;
block|}
end_expr_stmt
begin_elseif
elseif|else
if|if
condition|(
name|pattern
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|".warning"
argument_list|)
argument_list|)
condition|)
block|{
name|p
operator|=
name|QStringRef
argument_list|(
name|pattern
operator|.
name|string
argument_list|()
argument_list|,
name|pattern
operator|.
name|position
argument_list|()
argument_list|,
name|pattern
operator|.
name|length
argument_list|()
operator|-
name|strlen
argument_list|(
literal|".warning"
argument_list|)
argument_list|)
expr_stmt|;
name|messageType
operator|=
name|QtWarningMsg
expr_stmt|;
block|}
end_elseif
begin_elseif
elseif|else
if|if
condition|(
name|pattern
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|".critical"
argument_list|)
argument_list|)
condition|)
block|{
name|p
operator|=
name|QStringRef
argument_list|(
name|pattern
operator|.
name|string
argument_list|()
argument_list|,
name|pattern
operator|.
name|position
argument_list|()
argument_list|,
name|pattern
operator|.
name|length
argument_list|()
operator|-
name|strlen
argument_list|(
literal|".critical"
argument_list|)
argument_list|)
expr_stmt|;
name|messageType
operator|=
name|QtCriticalMsg
expr_stmt|;
block|}
end_elseif
begin_else
else|else
block|{
name|p
operator|=
name|pattern
expr_stmt|;
block|}
end_else
begin_if
if|if
condition|(
operator|!
name|p
operator|.
name|contains
argument_list|(
name|QLatin1Char
argument_list|(
literal|'*'
argument_list|)
argument_list|)
condition|)
block|{
name|flags
operator|=
name|FullText
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|p
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'*'
argument_list|)
argument_list|)
condition|)
block|{
name|flags
operator||=
name|LeftFilter
expr_stmt|;
name|p
operator|=
name|QStringRef
argument_list|(
name|p
operator|.
name|string
argument_list|()
argument_list|,
name|p
operator|.
name|position
argument_list|()
argument_list|,
name|p
operator|.
name|length
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|p
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'*'
argument_list|)
argument_list|)
condition|)
block|{
name|flags
operator||=
name|RightFilter
expr_stmt|;
name|p
operator|=
name|QStringRef
argument_list|(
name|p
operator|.
name|string
argument_list|()
argument_list|,
name|p
operator|.
name|position
argument_list|()
operator|+
literal|1
argument_list|,
name|p
operator|.
name|length
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|p
operator|.
name|contains
argument_list|(
name|QLatin1Char
argument_list|(
literal|'*'
argument_list|)
argument_list|)
condition|)
comment|// '*' only supported at start/end
name|flags
operator|=
literal|0
expr_stmt|;
block|}
end_if
begin_expr_stmt
name|category
operator|=
name|p
operator|.
name|toString
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
unit|}
comment|/*!     \class QLoggingSettingsParser     \since 5.3     \internal      Parses a .ini file with the following format:      [rules]     rule1=[true|false]     rule2=[true|false]     ...      [rules] is the default section, and therefore optional. */
end_comment
begin_comment
comment|/*!     \internal     Parses configuration from \a content. */
end_comment
begin_macro
unit|void
DECL|function|setContent
name|QLoggingSettingsParser
end_macro
begin_expr_stmt
DECL|function|setContent
operator|::
name|setContent
operator|(
specifier|const
name|QString
operator|&
name|content
operator|)
block|{
name|QString
name|content_
operator|=
name|content
block|;
name|QTextStream
name|stream
argument_list|(
operator|&
name|content_
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
block|;
name|setContent
argument_list|(
name|stream
argument_list|)
block|; }
comment|/*!     \internal     Parses configuration from \a stream. */
DECL|function|setContent
name|void
name|QLoggingSettingsParser
operator|::
name|setContent
operator|(
name|QTextStream
operator|&
name|stream
operator|)
block|{
name|_rules
operator|.
name|clear
argument_list|()
block|;
while|while
condition|(
operator|!
name|stream
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QString
name|line
init|=
name|stream
operator|.
name|readLine
argument_list|()
decl_stmt|;
comment|// Remove all whitespace from line
name|line
operator|=
name|line
operator|.
name|simplified
argument_list|()
expr_stmt|;
name|line
operator|.
name|remove
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|)
expr_stmt|;
comment|// comment
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|';'
argument_list|)
argument_list|)
condition|)
continue|continue;
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'['
argument_list|)
argument_list|)
operator|&&
name|line
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|']'
argument_list|)
argument_list|)
condition|)
block|{
comment|// new section
name|_section
operator|=
name|line
operator|.
name|mid
argument_list|(
literal|1
argument_list|,
name|line
operator|.
name|size
argument_list|()
operator|-
literal|2
argument_list|)
expr_stmt|;
continue|continue;
block|}
end_expr_stmt
begin_if
if|if
condition|(
name|_section
operator|==
name|QLatin1String
argument_list|(
literal|"Rules"
argument_list|)
condition|)
block|{
name|int
name|equalPos
init|=
name|line
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'='
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|equalPos
operator|!=
operator|-
literal|1
operator|)
operator|&&
operator|(
name|line
operator|.
name|lastIndexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'='
argument_list|)
argument_list|)
operator|==
name|equalPos
operator|)
condition|)
block|{
specifier|const
name|QStringRef
name|pattern
init|=
name|line
operator|.
name|leftRef
argument_list|(
name|equalPos
argument_list|)
decl_stmt|;
specifier|const
name|QStringRef
name|value
init|=
name|line
operator|.
name|midRef
argument_list|(
name|equalPos
operator|+
literal|1
argument_list|)
decl_stmt|;
name|bool
name|enabled
init|=
operator|(
name|value
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"true"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
operator|)
decl_stmt|;
name|QLoggingRule
name|rule
parameter_list|(
name|pattern
parameter_list|,
name|enabled
parameter_list|)
function_decl|;
if|if
condition|(
name|rule
operator|.
name|flags
operator|!=
literal|0
condition|)
name|_rules
operator|.
name|append
argument_list|(
name|rule
argument_list|)
expr_stmt|;
else|else
name|warnMsg
argument_list|(
literal|"Ignoring malformed logging rule: '%s'"
argument_list|,
name|line
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_if
begin_comment
unit|} }
comment|/*!     \internal     QLoggingRegistry constructor  */
end_comment
begin_constructor
DECL|function|QLoggingRegistry
name|QLoggingRegistry
operator|::
name|QLoggingRegistry
parameter_list|()
member_init_list|:
name|categoryFilter
argument_list|(
name|defaultCategoryFilter
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|qtLoggingDebug
specifier|static
name|bool
name|qtLoggingDebug
parameter_list|()
block|{
specifier|static
specifier|const
name|bool
name|debugEnv
init|=
name|qEnvironmentVariableIsSet
argument_list|(
literal|"QT_LOGGING_DEBUG"
argument_list|)
decl_stmt|;
return|return
name|debugEnv
return|;
block|}
end_function
begin_comment
comment|/*!     \internal     Initializes the rules database by loading     $QT_LOGGING_CONF, $QT_LOGGING_RULES, and .config/QtProject/qtlogging.ini.  */
end_comment
begin_function
DECL|function|init
name|void
name|QLoggingRegistry
operator|::
name|init
parameter_list|()
block|{
comment|// get rules from environment
specifier|const
name|QByteArray
name|rulesFilePath
init|=
name|qgetenv
argument_list|(
literal|"QT_LOGGING_CONF"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|rulesFilePath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QFile
name|file
argument_list|(
name|QFile
operator|::
name|decodeName
argument_list|(
name|rulesFilePath
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
condition|)
block|{
name|QTextStream
name|stream
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|QLoggingSettingsParser
name|parser
decl_stmt|;
name|parser
operator|.
name|setContent
argument_list|(
name|stream
argument_list|)
expr_stmt|;
if|if
condition|(
name|qtLoggingDebug
argument_list|()
condition|)
name|debugMsg
argument_list|(
literal|"Loading \"%s\" ..."
argument_list|,
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|file
operator|.
name|fileName
argument_list|()
argument_list|)
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|envRules
operator|=
name|parser
operator|.
name|rules
argument_list|()
expr_stmt|;
block|}
block|}
specifier|const
name|QByteArray
name|rulesSrc
init|=
name|qgetenv
argument_list|(
literal|"QT_LOGGING_RULES"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|rulesSrc
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QTextStream
name|stream
argument_list|(
name|rulesSrc
argument_list|)
decl_stmt|;
name|QLoggingSettingsParser
name|parser
decl_stmt|;
name|parser
operator|.
name|setSection
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Rules"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|setContent
argument_list|(
name|stream
argument_list|)
expr_stmt|;
name|envRules
operator|+=
name|parser
operator|.
name|rules
argument_list|()
expr_stmt|;
block|}
comment|// get rules from qt configuration
name|QString
name|envPath
init|=
name|QStandardPaths
operator|::
name|locate
argument_list|(
name|QStandardPaths
operator|::
name|GenericConfigLocation
argument_list|,
name|QStringLiteral
argument_list|(
literal|"QtProject/qtlogging.ini"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|envPath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QFile
name|file
argument_list|(
name|envPath
argument_list|)
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
condition|)
block|{
name|QTextStream
name|stream
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|QLoggingSettingsParser
name|parser
decl_stmt|;
name|parser
operator|.
name|setContent
argument_list|(
name|stream
argument_list|)
expr_stmt|;
if|if
condition|(
name|qtLoggingDebug
argument_list|()
condition|)
name|debugMsg
argument_list|(
literal|"Loading \"%s\" ..."
argument_list|,
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|envPath
argument_list|)
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|configRules
operator|=
name|parser
operator|.
name|rules
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|envRules
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|configRules
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|registryMutex
argument_list|)
decl_stmt|;
name|updateRules
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \internal     Registers a category object.      This method might be called concurrently for the same category object. */
end_comment
begin_function
DECL|function|registerCategory
name|void
name|QLoggingRegistry
operator|::
name|registerCategory
parameter_list|(
name|QLoggingCategory
modifier|*
name|cat
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|registryMutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|categories
operator|.
name|contains
argument_list|(
name|cat
argument_list|)
condition|)
block|{
name|categories
operator|.
name|append
argument_list|(
name|cat
argument_list|)
expr_stmt|;
call|(
modifier|*
name|categoryFilter
call|)
argument_list|(
name|cat
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \internal     Unregisters a category object. */
end_comment
begin_function
DECL|function|unregisterCategory
name|void
name|QLoggingRegistry
operator|::
name|unregisterCategory
parameter_list|(
name|QLoggingCategory
modifier|*
name|cat
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|registryMutex
argument_list|)
decl_stmt|;
name|categories
operator|.
name|removeOne
argument_list|(
name|cat
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal     Installs logging rules as specified in \a content.  */
end_comment
begin_function
DECL|function|setApiRules
name|void
name|QLoggingRegistry
operator|::
name|setApiRules
parameter_list|(
specifier|const
name|QString
modifier|&
name|content
parameter_list|)
block|{
name|QLoggingSettingsParser
name|parser
decl_stmt|;
name|parser
operator|.
name|setSection
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Rules"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|setContent
argument_list|(
name|content
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|registryMutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|qtLoggingDebug
argument_list|()
condition|)
name|debugMsg
argument_list|(
literal|"Loading logging rules set by Qt API ..."
argument_list|)
expr_stmt|;
name|apiRules
operator|=
name|parser
operator|.
name|rules
argument_list|()
expr_stmt|;
name|updateRules
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal     Activates a new set of logging rules for the default filter.      (The caller must lock registryMutex to make sure the API is thread safe.) */
end_comment
begin_function
DECL|function|updateRules
name|void
name|QLoggingRegistry
operator|::
name|updateRules
parameter_list|()
block|{
if|if
condition|(
name|categoryFilter
operator|!=
name|defaultCategoryFilter
condition|)
return|return;
name|rules
operator|=
name|configRules
operator|+
name|apiRules
operator|+
name|envRules
expr_stmt|;
foreach|foreach
control|(
name|QLoggingCategory
modifier|*
name|cat
decl|,
name|categories
control|)
call|(
modifier|*
name|categoryFilter
call|)
argument_list|(
name|cat
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal     Installs a custom filter rule. */
end_comment
begin_function
name|QLoggingCategory
operator|::
name|CategoryFilter
DECL|function|installFilter
name|QLoggingRegistry
operator|::
name|installFilter
parameter_list|(
name|QLoggingCategory
operator|::
name|CategoryFilter
name|filter
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|registryMutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|filter
operator|==
literal|0
condition|)
name|filter
operator|=
name|defaultCategoryFilter
expr_stmt|;
name|QLoggingCategory
operator|::
name|CategoryFilter
name|old
init|=
name|categoryFilter
decl_stmt|;
name|categoryFilter
operator|=
name|filter
expr_stmt|;
foreach|foreach
control|(
name|QLoggingCategory
modifier|*
name|cat
decl|,
name|categories
control|)
call|(
modifier|*
name|categoryFilter
call|)
argument_list|(
name|cat
argument_list|)
expr_stmt|;
return|return
name|old
return|;
block|}
end_function
begin_function
DECL|function|instance
name|QLoggingRegistry
modifier|*
name|QLoggingRegistry
operator|::
name|instance
parameter_list|()
block|{
return|return
name|qtLoggingRegistry
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \internal     Updates category settings according to rules. */
end_comment
begin_function
DECL|function|defaultCategoryFilter
name|void
name|QLoggingRegistry
operator|::
name|defaultCategoryFilter
parameter_list|(
name|QLoggingCategory
modifier|*
name|cat
parameter_list|)
block|{
comment|// QLoggingCategory() normalizes "default" strings
comment|// to qtDefaultCategoryName
name|bool
name|debug
init|=
literal|true
decl_stmt|;
name|char
name|c
decl_stmt|;
if|if
condition|(
operator|!
name|memcmp
argument_list|(
name|cat
operator|->
name|categoryName
argument_list|()
argument_list|,
literal|"qt"
argument_list|,
literal|2
argument_list|)
operator|&&
operator|(
operator|!
operator|(
name|c
operator|=
name|cat
operator|->
name|categoryName
argument_list|()
index|[
literal|2
index|]
operator|)
operator|||
name|c
operator|==
literal|'.'
operator|)
condition|)
name|debug
operator|=
literal|false
expr_stmt|;
name|bool
name|warning
init|=
literal|true
decl_stmt|;
name|bool
name|critical
init|=
literal|true
decl_stmt|;
name|QString
name|categoryName
init|=
name|QLatin1String
argument_list|(
name|cat
operator|->
name|categoryName
argument_list|()
argument_list|)
decl_stmt|;
name|QLoggingRegistry
modifier|*
name|reg
init|=
name|QLoggingRegistry
operator|::
name|instance
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QLoggingRule
modifier|&
name|item
decl|,
name|reg
operator|->
name|rules
control|)
block|{
name|int
name|filterpass
init|=
name|item
operator|.
name|pass
argument_list|(
name|categoryName
argument_list|,
name|QtDebugMsg
argument_list|)
decl_stmt|;
if|if
condition|(
name|filterpass
operator|!=
literal|0
condition|)
name|debug
operator|=
operator|(
name|filterpass
operator|>
literal|0
operator|)
expr_stmt|;
name|filterpass
operator|=
name|item
operator|.
name|pass
argument_list|(
name|categoryName
argument_list|,
name|QtWarningMsg
argument_list|)
expr_stmt|;
if|if
condition|(
name|filterpass
operator|!=
literal|0
condition|)
name|warning
operator|=
operator|(
name|filterpass
operator|>
literal|0
operator|)
expr_stmt|;
name|filterpass
operator|=
name|item
operator|.
name|pass
argument_list|(
name|categoryName
argument_list|,
name|QtCriticalMsg
argument_list|)
expr_stmt|;
if|if
condition|(
name|filterpass
operator|!=
literal|0
condition|)
name|critical
operator|=
operator|(
name|filterpass
operator|>
literal|0
operator|)
expr_stmt|;
block|}
name|cat
operator|->
name|setEnabled
argument_list|(
name|QtDebugMsg
argument_list|,
name|debug
argument_list|)
expr_stmt|;
name|cat
operator|->
name|setEnabled
argument_list|(
name|QtWarningMsg
argument_list|,
name|warning
argument_list|)
expr_stmt|;
name|cat
operator|->
name|setEnabled
argument_list|(
name|QtCriticalMsg
argument_list|,
name|critical
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
