begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (info@qt.nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSINTERNALMIME_H
end_ifndef
begin_define
DECL|macro|QWINDOWSINTERNALMIME_H
define|#
directive|define
name|QWINDOWSINTERNALMIME_H
end_define
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qdnd_p.h>
end_include
begin_comment
comment|// QInternalMime
end_comment
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Implementation in qwindowsclipboard.cpp.
end_comment
begin_decl_stmt
name|class
name|QWindowsInternalMimeData
range|:
name|public
name|QInternalMimeData
block|{
name|public
operator|:
name|virtual
name|bool
name|hasFormat_sys
argument_list|(
argument|const QString&mimetype
argument_list|)
specifier|const
block|;
name|virtual
name|QStringList
name|formats_sys
argument_list|()
specifier|const
block|;
name|virtual
name|QVariant
name|retrieveData_sys
argument_list|(
argument|const QString&mimetype
argument_list|,
argument|QVariant::Type preferredType
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|virtual
name|IDataObject
operator|*
name|retrieveDataObject
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|releaseDataObject
argument_list|(
argument|IDataObject *
argument_list|)
specifier|const
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|QMimeData
operator|&
name|m
operator|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSINTERNALMIME_H
end_comment
end_unit
