begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QINPUTPANEL_P_H
end_ifndef
begin_define
DECL|macro|QINPUTPANEL_P_H
define|#
directive|define
name|QINPUTPANEL_P_H
end_define
begin_include
include|#
directive|include
file|<qinputpanel.h>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QWeakPointer>
end_include
begin_include
include|#
directive|include
file|<QTransform>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|QInputPanelPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|public
operator|:
specifier|inline
name|QInputPanelPrivate
argument_list|()
operator|:
name|visible
argument_list|(
argument|false
argument_list|)
block|{}
name|QTransform
name|inputItemTransform
block|;
name|QWeakPointer
operator|<
name|QObject
operator|>
name|inputItem
block|;
name|bool
name|visible
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
