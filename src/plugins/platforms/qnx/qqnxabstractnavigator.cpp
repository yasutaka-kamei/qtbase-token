begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2012 Research In Motion ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxabstractnavigator.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QUrl>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNXNAVIGATOR_DEBUG
argument_list|)
end_if
begin_define
DECL|macro|qNavigatorDebug
define|#
directive|define
name|qNavigatorDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qNavigatorDebug
define|#
directive|define
name|qNavigatorDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QQnxAbstractNavigator
name|QQnxAbstractNavigator
operator|::
name|QQnxAbstractNavigator
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QQnxAbstractNavigator
name|QQnxAbstractNavigator
operator|::
name|~
name|QQnxAbstractNavigator
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|invokeUrl
name|bool
name|QQnxAbstractNavigator
operator|::
name|invokeUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
if|if
condition|(
operator|!
name|url
operator|.
name|isValid
argument_list|()
operator|||
name|url
operator|.
name|isRelative
argument_list|()
condition|)
return|return
literal|false
return|;
comment|// not using QUrl::toEncoded() because for e.g. camera:// it creates camera:
comment|// which is not recognized by the navigator anymore
specifier|const
name|bool
name|result
init|=
name|requestInvokeUrl
argument_list|(
name|url
operator|.
name|toString
argument_list|()
operator|.
name|toUtf8
argument_list|()
argument_list|)
decl_stmt|;
name|qNavigatorDebug
argument_list|()
operator|<<
literal|"url="
operator|<<
name|url
operator|<<
literal|"result="
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
