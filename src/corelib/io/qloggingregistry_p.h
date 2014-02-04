begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLOGGINGREGISTRY_P_H
end_ifndef
begin_define
DECL|macro|QLOGGINGREGISTRY_P_H
define|#
directive|define
name|QLOGGINGREGISTRY_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of a number of Qt sources files.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|<QtCore/qloggingcategory.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_decl_stmt
DECL|variable|tst_QLoggingRegistry
name|class
name|tst_QLoggingRegistry
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QLoggingRule
block|{
name|public
label|:
name|QLoggingRule
argument_list|()
expr_stmt|;
name|QLoggingRule
argument_list|(
argument|const QString&pattern
argument_list|,
argument|bool enabled
argument_list|)
empty_stmt|;
name|int
name|pass
argument_list|(
specifier|const
name|QString
operator|&
name|categoryName
argument_list|,
name|QtMsgType
name|type
argument_list|)
decl|const
decl_stmt|;
enum|enum
name|PatternFlag
block|{
name|Invalid
init|=
literal|0x0
block|,
name|FullText
init|=
literal|0x1
block|,
name|LeftFilter
init|=
literal|0x2
block|,
name|RightFilter
init|=
literal|0x4
block|,
name|MidFilter
init|=
name|LeftFilter
operator||
name|RightFilter
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|PatternFlags
argument_list|,
argument|PatternFlag
argument_list|)
name|QString
name|pattern
decl_stmt|;
name|PatternFlags
name|flags
decl_stmt|;
name|bool
name|enabled
decl_stmt|;
name|private
label|:
name|void
name|parse
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QLoggingRule::PatternFlags
argument_list|)
end_macro
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QLoggingRule
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QLoggingSettingsParser
block|{
name|public
label|:
name|void
name|setSection
parameter_list|(
specifier|const
name|QString
modifier|&
name|section
parameter_list|)
block|{
name|_section
operator|=
name|section
expr_stmt|;
block|}
name|void
name|setContent
parameter_list|(
specifier|const
name|QString
modifier|&
name|content
parameter_list|)
function_decl|;
name|void
name|setContent
parameter_list|(
name|QTextStream
modifier|&
name|stream
parameter_list|)
function_decl|;
name|QVector
operator|<
name|QLoggingRule
operator|>
name|rules
argument_list|()
specifier|const
block|{
return|return
name|_rules
return|;
block|}
name|private
label|:
name|QString
name|_section
decl_stmt|;
name|QVector
operator|<
name|QLoggingRule
operator|>
name|_rules
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QLoggingRegistry
block|{
name|public
label|:
name|QLoggingRegistry
argument_list|()
expr_stmt|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|registerCategory
parameter_list|(
name|QLoggingCategory
modifier|*
name|category
parameter_list|)
function_decl|;
name|void
name|unregisterCategory
parameter_list|(
name|QLoggingCategory
modifier|*
name|category
parameter_list|)
function_decl|;
name|void
name|setApiRules
parameter_list|(
specifier|const
name|QString
modifier|&
name|content
parameter_list|)
function_decl|;
name|QLoggingCategory
operator|::
name|CategoryFilter
name|installFilter
argument_list|(
argument|QLoggingCategory::CategoryFilter filter
argument_list|)
expr_stmt|;
specifier|static
name|QLoggingRegistry
modifier|*
name|instance
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|updateRules
parameter_list|()
function_decl|;
specifier|static
name|void
name|defaultCategoryFilter
parameter_list|(
name|QLoggingCategory
modifier|*
name|category
parameter_list|)
function_decl|;
name|QMutex
name|registryMutex
decl_stmt|;
name|QVector
operator|<
name|QLoggingRule
operator|>
name|configRules
expr_stmt|;
name|QVector
operator|<
name|QLoggingRule
operator|>
name|envRules
expr_stmt|;
name|QVector
operator|<
name|QLoggingRule
operator|>
name|apiRules
expr_stmt|;
name|QVector
operator|<
name|QLoggingRule
operator|>
name|rules
expr_stmt|;
name|QList
operator|<
name|QLoggingCategory
operator|*
operator|>
name|categories
expr_stmt|;
name|QLoggingCategory
operator|::
name|CategoryFilter
name|categoryFilter
expr_stmt|;
name|friend
name|class
operator|::
name|tst_QLoggingRegistry
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLOGGINGREGISTRY_P_H
end_comment
end_unit
