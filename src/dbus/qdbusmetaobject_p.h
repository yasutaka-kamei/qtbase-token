begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|QDBUSMETAOBJECTPRIVATE_H
end_ifndef
begin_define
DECL|macro|QDBUSMETAOBJECTPRIVATE_H
define|#
directive|define
name|QDBUSMETAOBJECTPRIVATE_H
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
name|d
operator|.
name|stringdata
block|;
name|delete
index|[]
name|d
operator|.
name|data
block|;     }
comment|// methods (slots& signals):
specifier|const
name|char
operator|*
name|dbusNameForMethod
argument_list|(
argument|int id
argument_list|)
specifier|const
block|;
specifier|const
name|char
operator|*
name|inputSignatureForMethod
argument_list|(
argument|int id
argument_list|)
specifier|const
block|;
specifier|const
name|char
operator|*
name|outputSignatureForMethod
argument_list|(
argument|int id
argument_list|)
specifier|const
block|;
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
end_unit
