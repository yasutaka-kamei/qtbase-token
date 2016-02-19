begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSEXTRATYPES_H
end_ifndef
begin_define
DECL|macro|QDBUSEXTRATYPES_H
define|#
directive|define
name|QDBUSEXTRATYPES_H
end_define
begin_comment
comment|// define some useful types for D-BUS
end_comment
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusmacros.h>
end_include
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|6
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/qhashfunctions.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_DBUS_EXPORT
name|QDBusObjectPath
block|{
name|QString
name|m_path
decl_stmt|;
name|public
label|:
name|QDBusObjectPath
argument_list|()
name|Q_DECL_NOTHROW
label|:
name|m_path
argument_list|()
block|{}
comment|// compiler-generated copy/move constructor/assignment operators are ok!
comment|// compiler-generated destructor is ok!
specifier|inline
name|explicit
name|QDBusObjectPath
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
specifier|inline
name|explicit
name|QDBusObjectPath
parameter_list|(
name|QLatin1String
name|path
parameter_list|)
function_decl|;
specifier|inline
name|explicit
name|QDBusObjectPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|explicit
name|QDBusObjectPath
argument_list|(
name|QString
operator|&&
name|p
argument_list|)
range|:
name|m_path
argument_list|(
argument|std::move(p)
argument_list|)
block|{
name|doCheck
argument_list|()
block|; }
endif|#
directive|endif
name|void
name|swap
argument_list|(
argument|QDBusObjectPath&other
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|qSwap
argument_list|(
name|m_path
argument_list|,
name|other
operator|.
name|m_path
argument_list|)
block|; }
specifier|inline
name|void
name|setPath
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
decl_stmt|;
specifier|inline
name|QString
name|path
argument_list|()
specifier|const
block|{
return|return
name|m_path
return|;
block|}
name|private
label|:
name|void
name|doCheck
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED_NOT_MOVABLE_UNTIL_QT6
name|Q_DECLARE_SHARED_NOT_MOVABLE_UNTIL_QT6
argument_list|(
argument|QDBusObjectPath
argument_list|)
end_macro
begin_expr_stmt
specifier|inline
name|QDBusObjectPath
operator|::
name|QDBusObjectPath
argument_list|(
specifier|const
name|char
operator|*
name|objectPath
argument_list|)
operator|:
name|m_path
argument_list|(
argument|QString::fromLatin1(objectPath)
argument_list|)
block|{
name|doCheck
argument_list|()
block|; }
DECL|function|QDBusObjectPath
specifier|inline
name|QDBusObjectPath
operator|::
name|QDBusObjectPath
argument_list|(
argument|QLatin1String objectPath
argument_list|)
operator|:
name|m_path
argument_list|(
argument|objectPath
argument_list|)
block|{
name|doCheck
argument_list|()
block|; }
DECL|function|QDBusObjectPath
specifier|inline
name|QDBusObjectPath
operator|::
name|QDBusObjectPath
argument_list|(
specifier|const
name|QString
operator|&
name|objectPath
argument_list|)
operator|:
name|m_path
argument_list|(
argument|objectPath
argument_list|)
block|{
name|doCheck
argument_list|()
block|; }
DECL|function|setPath
specifier|inline
name|void
name|QDBusObjectPath
operator|::
name|setPath
argument_list|(
argument|const QString&objectPath
argument_list|)
block|{
name|m_path
operator|=
name|objectPath
block|;
name|doCheck
argument_list|()
block|; }
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QDBusObjectPath
operator|&
name|lhs
operator|,
specifier|const
name|QDBusObjectPath
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|path
argument_list|()
operator|==
name|rhs
operator|.
name|path
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QDBusObjectPath
operator|&
name|lhs
operator|,
specifier|const
name|QDBusObjectPath
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|path
argument_list|()
operator|!=
name|rhs
operator|.
name|path
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QDBusObjectPath
operator|&
name|lhs
operator|,
specifier|const
name|QDBusObjectPath
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|path
argument_list|()
operator|<
name|rhs
operator|.
name|path
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|QDBusObjectPath
modifier|&
name|objectPath
parameter_list|,
name|uint
name|seed
init|=
literal|0
parameter_list|)
block|{
return|return
name|qHash
argument_list|(
name|objectPath
operator|.
name|path
argument_list|()
argument_list|,
name|seed
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
name|class
name|Q_DBUS_EXPORT
name|QDBusSignature
block|{
name|QString
name|m_signature
decl_stmt|;
name|public
label|:
name|QDBusSignature
argument_list|()
name|Q_DECL_NOTHROW
label|:
name|m_signature
argument_list|()
block|{}
comment|// compiler-generated copy/move constructor/assignment operators are ok!
comment|// compiler-generated destructor is ok!
specifier|inline
name|explicit
name|QDBusSignature
parameter_list|(
specifier|const
name|char
modifier|*
name|signature
parameter_list|)
function_decl|;
specifier|inline
name|explicit
name|QDBusSignature
parameter_list|(
name|QLatin1String
name|signature
parameter_list|)
function_decl|;
specifier|inline
name|explicit
name|QDBusSignature
parameter_list|(
specifier|const
name|QString
modifier|&
name|signature
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|explicit
name|QDBusSignature
argument_list|(
name|QString
operator|&&
name|sig
argument_list|)
range|:
name|m_signature
argument_list|(
argument|std::move(sig)
argument_list|)
block|{
name|doCheck
argument_list|()
block|; }
endif|#
directive|endif
name|void
name|swap
argument_list|(
argument|QDBusSignature&other
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|qSwap
argument_list|(
name|m_signature
argument_list|,
name|other
operator|.
name|m_signature
argument_list|)
block|; }
specifier|inline
name|void
name|setSignature
argument_list|(
specifier|const
name|QString
operator|&
name|signature
argument_list|)
decl_stmt|;
specifier|inline
name|QString
name|signature
argument_list|()
specifier|const
block|{
return|return
name|m_signature
return|;
block|}
name|private
label|:
name|void
name|doCheck
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED_NOT_MOVABLE_UNTIL_QT6
name|Q_DECLARE_SHARED_NOT_MOVABLE_UNTIL_QT6
argument_list|(
argument|QDBusSignature
argument_list|)
end_macro
begin_expr_stmt
specifier|inline
name|QDBusSignature
operator|::
name|QDBusSignature
argument_list|(
specifier|const
name|char
operator|*
name|dBusSignature
argument_list|)
operator|:
name|m_signature
argument_list|(
argument|QString::fromLatin1(dBusSignature)
argument_list|)
block|{
name|doCheck
argument_list|()
block|; }
DECL|function|QDBusSignature
specifier|inline
name|QDBusSignature
operator|::
name|QDBusSignature
argument_list|(
argument|QLatin1String dBusSignature
argument_list|)
operator|:
name|m_signature
argument_list|(
argument|dBusSignature
argument_list|)
block|{
name|doCheck
argument_list|()
block|; }
DECL|function|QDBusSignature
specifier|inline
name|QDBusSignature
operator|::
name|QDBusSignature
argument_list|(
specifier|const
name|QString
operator|&
name|dBusSignature
argument_list|)
operator|:
name|m_signature
argument_list|(
argument|dBusSignature
argument_list|)
block|{
name|doCheck
argument_list|()
block|; }
DECL|function|setSignature
specifier|inline
name|void
name|QDBusSignature
operator|::
name|setSignature
argument_list|(
argument|const QString&dBusSignature
argument_list|)
block|{
name|m_signature
operator|=
name|dBusSignature
block|;
name|doCheck
argument_list|()
block|; }
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QDBusSignature
operator|&
name|lhs
operator|,
specifier|const
name|QDBusSignature
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|signature
argument_list|()
operator|==
name|rhs
operator|.
name|signature
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QDBusSignature
operator|&
name|lhs
operator|,
specifier|const
name|QDBusSignature
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|signature
argument_list|()
operator|!=
name|rhs
operator|.
name|signature
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QDBusSignature
operator|&
name|lhs
operator|,
specifier|const
name|QDBusSignature
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|signature
argument_list|()
operator|<
name|rhs
operator|.
name|signature
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|QDBusSignature
modifier|&
name|signature
parameter_list|,
name|uint
name|seed
init|=
literal|0
parameter_list|)
block|{
return|return
name|qHash
argument_list|(
name|signature
operator|.
name|signature
argument_list|()
argument_list|,
name|seed
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
name|class
name|QDBusVariant
block|{
name|QVariant
name|m_variant
decl_stmt|;
name|public
label|:
name|QDBusVariant
argument_list|()
name|Q_DECL_NOTHROW
label|:
name|m_variant
argument_list|()
block|{}
comment|// compiler-generated copy/move constructor/assignment operators are ok!
comment|// compiler-generated destructor is ok!
specifier|inline
name|explicit
name|QDBusVariant
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|variant
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|explicit
name|QDBusVariant
argument_list|(
name|QVariant
operator|&&
name|v
argument_list|)
name|Q_DECL_NOTHROW
range|:
name|m_variant
argument_list|(
argument|std::move(v)
argument_list|)
block|{}
endif|#
directive|endif
name|void
name|swap
argument_list|(
argument|QDBusVariant&other
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|qSwap
argument_list|(
name|m_variant
argument_list|,
name|other
operator|.
name|m_variant
argument_list|)
block|; }
specifier|inline
name|void
name|setVariant
argument_list|(
specifier|const
name|QVariant
operator|&
name|variant
argument_list|)
decl_stmt|;
specifier|inline
name|QVariant
name|variant
argument_list|()
specifier|const
block|{
return|return
name|m_variant
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED_NOT_MOVABLE_UNTIL_QT6
name|Q_DECLARE_SHARED_NOT_MOVABLE_UNTIL_QT6
argument_list|(
argument|QDBusVariant
argument_list|)
end_macro
begin_expr_stmt
specifier|inline
name|QDBusVariant
operator|::
name|QDBusVariant
argument_list|(
specifier|const
name|QVariant
operator|&
name|dBusVariant
argument_list|)
operator|:
name|m_variant
argument_list|(
argument|dBusVariant
argument_list|)
block|{ }
DECL|function|setVariant
specifier|inline
name|void
name|QDBusVariant
operator|::
name|setVariant
argument_list|(
argument|const QVariant&dBusVariant
argument_list|)
block|{
name|m_variant
operator|=
name|dBusVariant
block|; }
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QDBusVariant
operator|&
name|v1
operator|,
specifier|const
name|QDBusVariant
operator|&
name|v2
operator|)
block|{
return|return
name|v1
operator|.
name|variant
argument_list|()
operator|==
name|v2
operator|.
name|variant
argument_list|()
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusVariant
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusObjectPath
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusSignature
argument_list|)
end_decl_stmt
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
