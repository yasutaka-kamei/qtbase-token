begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSXMLPARSER_P_H
end_ifndef
begin_define
DECL|macro|QDBUSXMLPARSER_P_H
define|#
directive|define
name|QDBUSXMLPARSER_P_H
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
comment|// of the QLibrary class.  This header file may change from
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
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<qdbusmacros.h>
end_include
begin_include
include|#
directive|include
file|"qdbusintrospection_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*!     \internal */
name|class
name|QDBusXmlParser
block|{
name|QString
name|m_service
decl_stmt|;
name|QString
name|m_path
decl_stmt|;
name|QSharedDataPointer
operator|<
name|QDBusIntrospection
operator|::
name|Object
operator|>
name|m_object
expr_stmt|;
name|QDBusIntrospection
operator|::
name|Interfaces
name|m_interfaces
expr_stmt|;
name|public
label|:
name|QDBusXmlParser
argument_list|(
specifier|const
name|QString
operator|&
name|service
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QString
operator|&
name|xmlData
argument_list|)
expr_stmt|;
specifier|inline
name|QDBusIntrospection
operator|::
name|Interfaces
name|interfaces
argument_list|()
specifier|const
block|{
return|return
name|m_interfaces
return|;
block|}
specifier|inline
name|QSharedDataPointer
operator|<
name|QDBusIntrospection
operator|::
name|Object
operator|>
name|object
argument_list|()
specifier|const
block|{
return|return
name|m_object
return|;
block|}
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
comment|// QT_NO_DBUS
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
