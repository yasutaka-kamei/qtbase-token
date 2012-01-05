begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|IAPCONF_H
end_ifndef
begin_define
DECL|macro|IAPCONF_H
define|#
directive|define
name|IAPCONF_H
end_define
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_decl_stmt
name|namespace
name|Maemo
block|{
name|class
name|IAPConfPrivate
decl_stmt|;
name|class
name|IAPConf
block|{
name|public
label|:
name|IAPConf
argument_list|(
specifier|const
name|QString
operator|&
name|iap_id
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|IAPConf
argument_list|()
expr_stmt|;
comment|/**         Get one IAP value.     */
name|QVariant
name|value
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
comment|/**         Return all the IAPs found in the system. If return_path is true, 	then do not strip the IAP path away.     */
specifier|static
name|void
name|getAll
argument_list|(
name|QList
operator|<
name|QString
operator|>
operator|&
name|all_iaps
argument_list|,
name|bool
name|return_path
operator|=
name|false
argument_list|)
decl_stmt|;
name|private
label|:
name|IAPConfPrivate
modifier|*
name|d_ptr
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace Maemo
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
