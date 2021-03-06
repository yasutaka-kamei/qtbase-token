begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CUSTOMWIDGETSINFO_H
end_ifndef
begin_define
DECL|macro|CUSTOMWIDGETSINFO_H
define|#
directive|define
name|CUSTOMWIDGETSINFO_H
end_define
begin_include
include|#
directive|include
file|"treewalker.h"
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|Driver
name|class
name|Driver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomScript
name|class
name|DomScript
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|CustomWidgetsInfo
range|:
name|public
name|TreeWalker
block|{
name|public
operator|:
name|CustomWidgetsInfo
argument_list|()
block|;
name|void
name|acceptUI
argument_list|(
argument|DomUI *node
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|acceptCustomWidgets
argument_list|(
argument|DomCustomWidgets *node
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|acceptCustomWidget
argument_list|(
argument|DomCustomWidget *node
argument_list|)
name|Q_DECL_OVERRIDE
block|;
specifier|inline
name|QStringList
name|customWidgets
argument_list|()
specifier|const
block|{
return|return
name|m_customWidgets
operator|.
name|keys
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|hasCustomWidget
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|{
return|return
name|m_customWidgets
operator|.
name|contains
argument_list|(
name|name
argument_list|)
return|;
block|}
specifier|inline
name|DomCustomWidget
operator|*
name|customWidget
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|{
return|return
name|m_customWidgets
operator|.
name|value
argument_list|(
name|name
argument_list|)
return|;
block|}
name|DomScript
operator|*
name|customWidgetScript
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|;
name|QString
name|customWidgetAddPageMethod
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|;
name|QString
name|realClassName
argument_list|(
argument|const QString&className
argument_list|)
specifier|const
block|;
name|bool
name|extends
argument_list|(
argument|const QString&className
argument_list|,
argument|QLatin1String baseClassName
argument_list|)
specifier|const
block|;
name|bool
name|isCustomWidgetContainer
argument_list|(
argument|const QString&className
argument_list|)
specifier|const
block|;
name|private
operator|:
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|DomCustomWidget
operator|*
operator|>
name|NameCustomWidgetMap
expr_stmt|;
name|NameCustomWidgetMap
name|m_customWidgets
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// CUSTOMWIDGETSINFO_H
end_comment
end_unit
