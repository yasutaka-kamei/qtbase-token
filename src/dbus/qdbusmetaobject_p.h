begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
comment|// This file is not part of the public API.  This header file may
end_comment
begin_comment
comment|// change from version to version without notice, or even be
end_comment
begin_comment
comment|// removed.
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
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSMETAOBJECT_P_H
end_ifndef
begin_define
DECL|macro|QDBUSMETAOBJECT_P_H
define|#
directive|define
name|QDBUSMETAOBJECT_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qmetaobject.h>
end_include
begin_include
include|#
directive|include
file|<qdbusmacros.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusError
name|class
name|QDBusError
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QDBusMetaObjectPrivate
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|struct|QMetaObject
name|struct
name|Q_DBUS_EXPORT
name|QDBusMetaObject
range|:
name|public
name|QMetaObject
block|{
DECL|member|cached
name|bool
name|cached
block|;
specifier|static
name|QDBusMetaObject
operator|*
name|createMetaObject
argument_list|(
specifier|const
name|QString
operator|&
name|interface
argument_list|,
specifier|const
name|QString
operator|&
name|xml
argument_list|,
name|QHash
operator|<
name|QString
argument_list|,
name|QDBusMetaObject
operator|*
operator|>
operator|&
name|map
argument_list|,
name|QDBusError
operator|&
name|error
argument_list|)
block|;
DECL|function|~QDBusMetaObject
operator|~
name|QDBusMetaObject
argument_list|()
block|{
name|delete
index|[]
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|d
operator|.
name|stringdata
operator|)
block|;
name|delete
index|[]
name|d
operator|.
name|data
block|;     }
comment|// methods (slots& signals):
specifier|const
name|int
operator|*
name|inputTypesForMethod
argument_list|(
argument|int id
argument_list|)
specifier|const
block|;
specifier|const
name|int
operator|*
name|outputTypesForMethod
argument_list|(
argument|int id
argument_list|)
specifier|const
block|;
comment|// properties:
name|int
name|propertyMetaType
argument_list|(
argument|int id
argument_list|)
specifier|const
block|;
DECL|member|private
name|private
operator|:
name|QDBusMetaObject
argument_list|()
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
comment|// QT_NO_DBUS
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
