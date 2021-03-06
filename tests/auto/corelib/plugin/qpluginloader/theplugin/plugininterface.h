begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PLUGININTERFACE_H
end_ifndef
begin_define
DECL|macro|PLUGININTERFACE_H
define|#
directive|define
name|PLUGININTERFACE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QtGlobal>
end_include
begin_struct
DECL|struct|PluginInterface
struct|struct
name|PluginInterface
block|{
DECL|function|~PluginInterface
name|virtual
operator|~
name|PluginInterface
argument_list|()
block|{}
name|virtual
name|QString
name|pluginName
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|macro|PluginInterface_iid
define|#
directive|define
name|PluginInterface_iid
value|"org.qt-project.Qt.autotests.plugininterface"
name|Q_DECLARE_INTERFACE
argument_list|(
name|PluginInterface
argument_list|,
name|PluginInterface_iid
argument_list|)
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PLUGININTERFACE_H
end_comment
end_unit
