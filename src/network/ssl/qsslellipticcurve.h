begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Governikus GmbH& Co. KG. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLELLIPTICCURVE_H
end_ifndef
begin_define
DECL|macro|QSSLELLIPTICCURVE_H
define|#
directive|define
name|QSSLELLIPTICCURVE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QtGlobal>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMetaType>
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
file|<QtCore/QHash>
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSslEllipticCurve
name|class
name|QSslEllipticCurve
decl_stmt|;
end_decl_stmt
begin_comment
comment|// qHash is a friend, but we can't use default arguments for friends (Â§8.3.6.4)
end_comment
begin_decl_stmt
name|Q_DECL_CONSTEXPR
name|uint
name|qHash
argument_list|(
name|QSslEllipticCurve
name|curve
argument_list|,
name|uint
name|seed
operator|=
literal|0
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QSslEllipticCurve
block|{
name|public
label|:
name|Q_DECL_CONSTEXPR
name|QSslEllipticCurve
argument_list|()
name|Q_DECL_NOTHROW
operator|:
name|id
argument_list|(
literal|0
argument_list|)
block|{     }
name|Q_NETWORK_EXPORT
specifier|static
name|QSslEllipticCurve
name|fromShortName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
expr_stmt|;
name|Q_NETWORK_EXPORT
specifier|static
name|QSslEllipticCurve
name|fromLongName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|Q_NETWORK_EXPORT
name|QString
name|shortName
argument_list|()
specifier|const
name|Q_REQUIRED_RESULT
expr_stmt|;
name|Q_NETWORK_EXPORT
name|QString
name|longName
argument_list|()
specifier|const
name|Q_REQUIRED_RESULT
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|id
operator|!=
literal|0
return|;
block|}
name|Q_NETWORK_EXPORT
name|bool
name|isTlsNamedCurve
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|private
label|:
name|int
name|id
decl_stmt|;
name|friend
name|Q_DECL_CONSTEXPR
name|bool
name|operator
operator|==
operator|(
name|QSslEllipticCurve
name|lhs
operator|,
name|QSslEllipticCurve
name|rhs
operator|)
name|Q_DECL_NOTHROW
expr_stmt|;
name|friend
name|Q_DECL_CONSTEXPR
name|uint
name|qHash
argument_list|(
name|QSslEllipticCurve
name|curve
argument_list|,
name|uint
name|seed
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|friend
name|class
name|QSslSocketPrivate
decl_stmt|;
name|friend
name|class
name|QSslSocketBackendPrivate
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QSslEllipticCurve
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
name|Q_DECL_CONSTEXPR
specifier|inline
name|uint
name|qHash
parameter_list|(
name|QSslEllipticCurve
name|curve
parameter_list|,
name|uint
name|seed
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|qHash
argument_list|(
name|curve
operator|.
name|id
argument_list|,
name|seed
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|QSslEllipticCurve
name|lhs
operator|,
name|QSslEllipticCurve
name|rhs
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
name|lhs
operator|.
name|id
operator|==
name|rhs
operator|.
name|id
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|QSslEllipticCurve
name|lhs
operator|,
name|QSslEllipticCurve
name|rhs
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|lhs
operator|,
name|rhs
operator|)
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_decl_stmt
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_NETWORK_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
name|QSslEllipticCurve
name|curve
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QSslEllipticCurve
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSSLELLIPTICCURVE_H
end_comment
end_unit
