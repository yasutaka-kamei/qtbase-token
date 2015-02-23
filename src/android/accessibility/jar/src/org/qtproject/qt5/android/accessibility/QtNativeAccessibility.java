begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the Android port of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_package
DECL|package|org.qtproject.qt5.android.accessibility
package|package
name|org
operator|.
name|qtproject
operator|.
name|qt5
operator|.
name|android
operator|.
name|accessibility
package|;
end_package
begin_import
import|import
name|android
operator|.
name|graphics
operator|.
name|Rect
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|accessibility
operator|.
name|AccessibilityNodeInfo
import|;
end_import
begin_class
DECL|class|QtNativeAccessibility
class|class
name|QtNativeAccessibility
block|{
DECL|method|setActive
specifier|static
specifier|native
name|void
name|setActive
parameter_list|(
name|boolean
name|enable
parameter_list|)
function_decl|;
DECL|method|childIdListForAccessibleObject
specifier|static
specifier|native
name|int
index|[]
name|childIdListForAccessibleObject
parameter_list|(
name|int
name|objectId
parameter_list|)
function_decl|;
DECL|method|parentId
specifier|static
specifier|native
name|int
name|parentId
parameter_list|(
name|int
name|objectId
parameter_list|)
function_decl|;
DECL|method|descriptionForAccessibleObject
specifier|static
specifier|native
name|String
name|descriptionForAccessibleObject
parameter_list|(
name|int
name|objectId
parameter_list|)
function_decl|;
DECL|method|screenRect
specifier|static
specifier|native
name|Rect
name|screenRect
parameter_list|(
name|int
name|objectId
parameter_list|)
function_decl|;
DECL|method|hitTest
specifier|static
specifier|native
name|int
name|hitTest
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|)
function_decl|;
DECL|method|clickAction
specifier|static
specifier|native
name|boolean
name|clickAction
parameter_list|(
name|int
name|objectId
parameter_list|)
function_decl|;
DECL|method|scrollForward
specifier|static
specifier|native
name|boolean
name|scrollForward
parameter_list|(
name|int
name|objectId
parameter_list|)
function_decl|;
DECL|method|scrollBackward
specifier|static
specifier|native
name|boolean
name|scrollBackward
parameter_list|(
name|int
name|objectId
parameter_list|)
function_decl|;
DECL|method|populateNode
specifier|static
specifier|native
name|boolean
name|populateNode
parameter_list|(
name|int
name|objectId
parameter_list|,
name|AccessibilityNodeInfo
name|node
parameter_list|)
function_decl|;
block|}
end_class
end_unit
