begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMETAOBJECT_P_H
end_ifndef
begin_define
DECL|macro|QMETAOBJECT_P_H
define|#
directive|define
name|QMETAOBJECT_P_H
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
comment|// of moc.  This header file may change from version to version without notice,
end_comment
begin_comment
comment|// or even be removed.
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
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobjectdefs.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
end_ifndef
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_comment
comment|// For QObjectPrivate::Connection
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/qvarlengtharray.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|enum|PropertyFlags
name|enum
name|PropertyFlags
block|{
DECL|enumerator|Invalid
name|Invalid
operator|=
literal|0x00000000
operator|,
DECL|enumerator|Readable
name|Readable
operator|=
literal|0x00000001
operator|,
DECL|enumerator|Writable
name|Writable
operator|=
literal|0x00000002
operator|,
DECL|enumerator|Resettable
name|Resettable
operator|=
literal|0x00000004
operator|,
DECL|enumerator|EnumOrFlag
name|EnumOrFlag
operator|=
literal|0x00000008
operator|,
DECL|enumerator|StdCppSet
name|StdCppSet
operator|=
literal|0x00000100
operator|,
comment|//     Override = 0x00000200,
DECL|enumerator|Constant
name|Constant
operator|=
literal|0x00000400
operator|,
DECL|enumerator|Final
name|Final
operator|=
literal|0x00000800
operator|,
DECL|enumerator|Designable
name|Designable
operator|=
literal|0x00001000
operator|,
DECL|enumerator|ResolveDesignable
name|ResolveDesignable
operator|=
literal|0x00002000
operator|,
DECL|enumerator|Scriptable
name|Scriptable
operator|=
literal|0x00004000
operator|,
DECL|enumerator|ResolveScriptable
name|ResolveScriptable
operator|=
literal|0x00008000
operator|,
DECL|enumerator|Stored
name|Stored
operator|=
literal|0x00010000
operator|,
DECL|enumerator|ResolveStored
name|ResolveStored
operator|=
literal|0x00020000
operator|,
DECL|enumerator|Editable
name|Editable
operator|=
literal|0x00040000
operator|,
DECL|enumerator|ResolveEditable
name|ResolveEditable
operator|=
literal|0x00080000
operator|,
DECL|enumerator|User
name|User
operator|=
literal|0x00100000
operator|,
DECL|enumerator|ResolveUser
name|ResolveUser
operator|=
literal|0x00200000
operator|,
DECL|enumerator|Notify
name|Notify
operator|=
literal|0x00400000
operator|,
DECL|enumerator|Revisioned
name|Revisioned
operator|=
literal|0x00800000
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_enum
DECL|enum|MethodFlags
enum|enum
name|MethodFlags
block|{
DECL|enumerator|AccessPrivate
name|AccessPrivate
init|=
literal|0x00
block|,
DECL|enumerator|AccessProtected
name|AccessProtected
init|=
literal|0x01
block|,
DECL|enumerator|AccessPublic
name|AccessPublic
init|=
literal|0x02
block|,
DECL|enumerator|AccessMask
name|AccessMask
init|=
literal|0x03
block|,
comment|//mask
DECL|enumerator|MethodMethod
name|MethodMethod
init|=
literal|0x00
block|,
DECL|enumerator|MethodSignal
name|MethodSignal
init|=
literal|0x04
block|,
DECL|enumerator|MethodSlot
name|MethodSlot
init|=
literal|0x08
block|,
DECL|enumerator|MethodConstructor
name|MethodConstructor
init|=
literal|0x0c
block|,
DECL|enumerator|MethodTypeMask
name|MethodTypeMask
init|=
literal|0x0c
block|,
DECL|enumerator|MethodCompatibility
name|MethodCompatibility
init|=
literal|0x10
block|,
DECL|enumerator|MethodCloned
name|MethodCloned
init|=
literal|0x20
block|,
DECL|enumerator|MethodScriptable
name|MethodScriptable
init|=
literal|0x40
block|,
DECL|enumerator|MethodRevisioned
name|MethodRevisioned
init|=
literal|0x80
block|}
enum|;
end_enum
begin_enum
DECL|enum|MetaObjectFlags
enum|enum
name|MetaObjectFlags
block|{
DECL|enumerator|DynamicMetaObject
name|DynamicMetaObject
init|=
literal|0x01
block|,
DECL|enumerator|RequiresVariantMetaObject
name|RequiresVariantMetaObject
init|=
literal|0x02
block|}
enum|;
end_enum
begin_enum
DECL|enum|MetaDataFlags
enum|enum
name|MetaDataFlags
block|{
DECL|enumerator|IsUnresolvedType
name|IsUnresolvedType
init|=
literal|0x80000000
block|,
DECL|enumerator|TypeNameIndexMask
name|TypeNameIndexMask
init|=
literal|0x7FFFFFFF
block|}
enum|;
end_enum
begin_function_decl
specifier|extern
name|int
name|qMetaTypeTypeInternal
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|class
name|QArgumentType
block|{
name|public
label|:
name|QArgumentType
argument_list|(
argument|int type
argument_list|)
block|:
name|_type
argument_list|(
argument|type
argument_list|)
block|{}
name|QArgumentType
argument_list|(
specifier|const
name|QByteArray
operator|&
name|name
argument_list|)
operator|:
name|_type
argument_list|(
name|qMetaTypeTypeInternal
argument_list|(
name|name
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|)
operator|,
name|_name
argument_list|(
argument|name
argument_list|)
block|{}
name|QArgumentType
argument_list|()
operator|:
name|_type
argument_list|(
literal|0
argument_list|)
block|{}
name|int
name|type
argument_list|()
specifier|const
block|{
return|return
name|_type
return|;
block|}
name|QByteArray
name|name
argument_list|()
specifier|const
block|{
if|if
condition|(
name|_type
operator|&&
name|_name
operator|.
name|isEmpty
argument_list|()
condition|)
name|const_cast
operator|<
name|QArgumentType
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|_name
operator|=
name|QMetaType
operator|::
name|typeName
argument_list|(
name|_type
argument_list|)
expr_stmt|;
return|return
name|_name
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QArgumentType
operator|&
name|other
operator|)
specifier|const
block|{
if|if
condition|(
name|_type
condition|)
return|return
name|_type
operator|==
name|other
operator|.
name|_type
return|;
elseif|else
if|if
condition|(
name|other
operator|.
name|_type
condition|)
return|return
name|false
return|;
else|else
return|return
name|_name
operator|==
name|other
operator|.
name|_name
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QArgumentType
operator|&
name|other
operator|)
specifier|const
block|{
if|if
condition|(
name|_type
condition|)
return|return
name|_type
operator|!=
name|other
operator|.
name|_type
return|;
elseif|else
if|if
condition|(
name|other
operator|.
name|_type
condition|)
return|return
name|true
return|;
else|else
return|return
name|_name
operator|!=
name|other
operator|.
name|_name
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|int
name|_type
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QByteArray
name|_name
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|QArgumentType
DECL|typedef|QArgumentTypeArray
unit|};
typedef|typedef
name|QVarLengthArray
operator|<
name|QArgumentType
operator|,
literal|10
operator|>
name|QArgumentTypeArray
expr_stmt|;
end_typedef
begin_decl_stmt
DECL|variable|QMetaMethodPrivate
name|class
name|QMetaMethodPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMutex
name|class
name|QMutex
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QMetaObjectPrivate
struct|struct
name|QMetaObjectPrivate
block|{
DECL|enumerator|OutputRevision
enum|enum
block|{
name|OutputRevision
init|=
literal|7
block|}
enum|;
comment|// Used by moc, qmetaobjectbuilder and qdbus
DECL|member|revision
name|int
name|revision
decl_stmt|;
DECL|member|className
name|int
name|className
decl_stmt|;
DECL|member|classInfoCount
DECL|member|classInfoData
name|int
name|classInfoCount
decl_stmt|,
name|classInfoData
decl_stmt|;
DECL|member|methodCount
DECL|member|methodData
name|int
name|methodCount
decl_stmt|,
name|methodData
decl_stmt|;
DECL|member|propertyCount
DECL|member|propertyData
name|int
name|propertyCount
decl_stmt|,
name|propertyData
decl_stmt|;
DECL|member|enumeratorCount
DECL|member|enumeratorData
name|int
name|enumeratorCount
decl_stmt|,
name|enumeratorData
decl_stmt|;
DECL|member|constructorCount
DECL|member|constructorData
name|int
name|constructorCount
decl_stmt|,
name|constructorData
decl_stmt|;
comment|//since revision 2
DECL|member|flags
name|int
name|flags
decl_stmt|;
comment|//since revision 3
DECL|member|signalCount
name|int
name|signalCount
decl_stmt|;
comment|//since revision 4
comment|// revision 5 introduces changes in normalized signatures, no new members
comment|// revision 6 added qt_static_metacall as a member of each Q_OBJECT and inside QMetaObject itself
comment|// revision 7 is Qt 5
DECL|function|get
specifier|static
specifier|inline
specifier|const
name|QMetaObjectPrivate
modifier|*
name|get
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
name|metaobject
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|QMetaObjectPrivate
operator|*
operator|>
operator|(
name|metaobject
operator|->
name|d
operator|.
name|data
operator|)
return|;
block|}
specifier|static
name|int
name|originalClone
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
name|obj
parameter_list|,
name|int
name|local_method_index
parameter_list|)
function_decl|;
specifier|static
name|QByteArray
name|decodeMethodSignature
parameter_list|(
specifier|const
name|char
modifier|*
name|signature
parameter_list|,
name|QArgumentTypeArray
modifier|&
name|types
parameter_list|)
function_decl|;
specifier|static
name|int
name|indexOfSignalRelative
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
modifier|*
name|baseObject
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|QArgumentType
modifier|*
name|types
parameter_list|)
function_decl|;
specifier|static
name|int
name|indexOfSlotRelative
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
modifier|*
name|m
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|QArgumentType
modifier|*
name|types
parameter_list|)
function_decl|;
specifier|static
name|int
name|indexOfSignal
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
name|m
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|QArgumentType
modifier|*
name|types
parameter_list|)
function_decl|;
specifier|static
name|int
name|indexOfSlot
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
name|m
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|QArgumentType
modifier|*
name|types
parameter_list|)
function_decl|;
specifier|static
name|int
name|indexOfMethod
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
name|m
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|QArgumentType
modifier|*
name|types
parameter_list|)
function_decl|;
specifier|static
name|int
name|indexOfConstructor
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
name|m
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|QArgumentType
modifier|*
name|types
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
specifier|static
name|QMetaMethod
name|signal
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
name|m
parameter_list|,
name|int
name|signal_index
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
specifier|static
name|int
name|signalOffset
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
name|m
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
specifier|static
name|int
name|absoluteSignalCount
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
name|m
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
specifier|static
name|int
name|signalIndex
parameter_list|(
specifier|const
name|QMetaMethod
modifier|&
name|m
parameter_list|)
function_decl|;
specifier|static
name|bool
name|checkConnectArgs
parameter_list|(
name|int
name|signalArgc
parameter_list|,
specifier|const
name|QArgumentType
modifier|*
name|signalTypes
parameter_list|,
name|int
name|methodArgc
parameter_list|,
specifier|const
name|QArgumentType
modifier|*
name|methodTypes
parameter_list|)
function_decl|;
specifier|static
name|bool
name|checkConnectArgs
parameter_list|(
specifier|const
name|QMetaMethodPrivate
modifier|*
name|signal
parameter_list|,
specifier|const
name|QMetaMethodPrivate
modifier|*
name|method
parameter_list|)
function_decl|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|parameterTypeNamesFromSignature
argument_list|(
specifier|const
name|char
operator|*
name|signature
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
comment|//defined in qobject.cpp
DECL|enum|DisconnectType
DECL|enumerator|DisconnectAll
DECL|enumerator|DisconnectOne
enum|enum
name|DisconnectType
block|{
name|DisconnectAll
block|,
name|DisconnectOne
block|}
enum|;
specifier|static
name|void
name|memberIndexes
parameter_list|(
specifier|const
name|QObject
modifier|*
name|obj
parameter_list|,
specifier|const
name|QMetaMethod
modifier|&
name|member
parameter_list|,
name|int
modifier|*
name|signalIndex
parameter_list|,
name|int
modifier|*
name|methodIndex
parameter_list|)
function_decl|;
specifier|static
name|QObjectPrivate
operator|::
name|Connection
operator|*
name|connect
argument_list|(
argument|const QObject *sender
argument_list|,
argument|int signal_index
argument_list|,
argument|const QMetaObject *smeta
argument_list|,
argument|const QObject *receiver
argument_list|,
argument|int method_index_relative
argument_list|,
argument|const QMetaObject *rmeta =
literal|0
argument_list|,
argument|int type =
literal|0
argument_list|,
argument|int *types =
literal|0
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|disconnect
parameter_list|(
specifier|const
name|QObject
modifier|*
name|sender
parameter_list|,
name|int
name|signal_index
parameter_list|,
specifier|const
name|QMetaObject
modifier|*
name|smeta
parameter_list|,
specifier|const
name|QObject
modifier|*
name|receiver
parameter_list|,
name|int
name|method_index
parameter_list|,
name|void
modifier|*
modifier|*
name|slot
parameter_list|,
name|DisconnectType
init|=
name|DisconnectAll
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|bool
name|disconnectHelper
argument_list|(
name|QObjectPrivate
operator|::
name|Connection
operator|*
name|c
argument_list|,
specifier|const
name|QObject
operator|*
name|receiver
argument_list|,
name|int
name|method_index
argument_list|,
name|void
operator|*
operator|*
name|slot
argument_list|,
name|QMutex
operator|*
name|senderMutex
argument_list|,
name|DisconnectType
operator|=
name|DisconnectAll
argument_list|)
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct
begin_comment
comment|// For meta-object generators
end_comment
begin_enum
DECL|enumerator|MetaObjectPrivateFieldCount
enum|enum
block|{
name|MetaObjectPrivateFieldCount
init|=
sizeof|sizeof
argument_list|(
name|QMetaObjectPrivate
argument_list|)
operator|/
expr|sizeof
operator|(
name|int
operator|)
block|}
enum|;
end_enum
begin_ifndef
ifndef|#
directive|ifndef
name|UTILS_H
end_ifndef
begin_comment
comment|// mirrored in moc's utils.h
end_comment
begin_function
DECL|function|is_ident_char
specifier|static
specifier|inline
name|bool
name|is_ident_char
parameter_list|(
name|char
name|s
parameter_list|)
block|{
return|return
operator|(
operator|(
name|s
operator|>=
literal|'a'
operator|&&
name|s
operator|<=
literal|'z'
operator|)
operator|||
operator|(
name|s
operator|>=
literal|'A'
operator|&&
name|s
operator|<=
literal|'Z'
operator|)
operator|||
operator|(
name|s
operator|>=
literal|'0'
operator|&&
name|s
operator|<=
literal|'9'
operator|)
operator|||
name|s
operator|==
literal|'_'
operator|)
return|;
block|}
end_function
begin_function
DECL|function|is_space
specifier|static
specifier|inline
name|bool
name|is_space
parameter_list|(
name|char
name|s
parameter_list|)
block|{
return|return
operator|(
name|s
operator|==
literal|' '
operator|||
name|s
operator|==
literal|'\t'
operator|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*     This function is shared with moc.cpp. The implementation lives in qmetaobject_moc_p.h, which     should be included where needed. The declaration here is not used to avoid warnings from     the compiler about unused functions.  static QByteArray normalizeTypeInternal(const char *t, const char *e, bool fixScope = false, bool adjustConst = true); */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
