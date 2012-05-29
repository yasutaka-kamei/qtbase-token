begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformsurface.h"
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QPlatformSurface     \since 5.0     \internal     \preliminary     \ingroup qpa      \brief The QPlatformSurface class provides an abstraction for a surface.  */
DECL|function|~QPlatformSurface
name|QPlatformSurface
operator|::
name|~
name|QPlatformSurface
operator|(
operator|)
block|{  }
DECL|function|surface
name|QSurface
operator|*
name|QPlatformSurface
operator|::
name|surface
operator|(
operator|)
specifier|const
block|{
return|return
name|m_surface
return|;
block|}
end_expr_stmt
begin_constructor
DECL|function|QPlatformSurface
name|QPlatformSurface
operator|::
name|QPlatformSurface
parameter_list|(
name|QSurface
modifier|*
name|surface
parameter_list|)
member_init_list|:
name|m_surface
argument_list|(
name|surface
argument_list|)
block|{ }
end_constructor
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
