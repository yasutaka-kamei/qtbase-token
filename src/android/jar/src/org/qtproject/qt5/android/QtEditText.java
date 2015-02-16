begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the Android port of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_package
DECL|package|org.qtproject.qt5.android
package|package
name|org
operator|.
name|qtproject
operator|.
name|qt5
operator|.
name|android
package|;
end_package
begin_import
import|import
name|android
operator|.
name|content
operator|.
name|Context
import|;
end_import
begin_import
import|import
name|android
operator|.
name|text
operator|.
name|InputType
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|View
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|inputmethod
operator|.
name|EditorInfo
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|inputmethod
operator|.
name|InputConnection
import|;
end_import
begin_class
DECL|class|QtEditText
specifier|public
class|class
name|QtEditText
extends|extends
name|View
block|{
DECL|field|m_initialCapsMode
name|int
name|m_initialCapsMode
init|=
literal|0
decl_stmt|;
DECL|field|m_imeOptions
name|int
name|m_imeOptions
init|=
literal|0
decl_stmt|;
DECL|field|m_inputType
name|int
name|m_inputType
init|=
name|InputType
operator|.
name|TYPE_CLASS_TEXT
decl_stmt|;
DECL|field|m_optionsChanged
name|boolean
name|m_optionsChanged
init|=
literal|false
decl_stmt|;
DECL|field|m_activityDelegate
name|QtActivityDelegate
name|m_activityDelegate
decl_stmt|;
DECL|method|setImeOptions
specifier|public
name|void
name|setImeOptions
parameter_list|(
name|int
name|m_imeOptions
parameter_list|)
block|{
if|if
condition|(
name|m_imeOptions
operator|==
name|this
operator|.
name|m_imeOptions
condition|)
return|return;
name|this
operator|.
name|m_imeOptions
operator|=
name|m_imeOptions
expr_stmt|;
name|m_optionsChanged
operator|=
literal|true
expr_stmt|;
block|}
DECL|method|setInitialCapsMode
specifier|public
name|void
name|setInitialCapsMode
parameter_list|(
name|int
name|m_initialCapsMode
parameter_list|)
block|{
if|if
condition|(
name|m_initialCapsMode
operator|==
name|this
operator|.
name|m_initialCapsMode
condition|)
return|return;
name|this
operator|.
name|m_initialCapsMode
operator|=
name|m_initialCapsMode
expr_stmt|;
name|m_optionsChanged
operator|=
literal|true
expr_stmt|;
block|}
DECL|method|setInputType
specifier|public
name|void
name|setInputType
parameter_list|(
name|int
name|m_inputType
parameter_list|)
block|{
if|if
condition|(
name|m_inputType
operator|==
name|this
operator|.
name|m_inputType
condition|)
return|return;
name|this
operator|.
name|m_inputType
operator|=
name|m_inputType
expr_stmt|;
name|m_optionsChanged
operator|=
literal|true
expr_stmt|;
block|}
DECL|method|QtEditText
specifier|public
name|QtEditText
parameter_list|(
name|Context
name|context
parameter_list|,
name|QtActivityDelegate
name|activityDelegate
parameter_list|)
block|{
name|super
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|setFocusable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setFocusableInTouchMode
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|m_activityDelegate
operator|=
name|activityDelegate
expr_stmt|;
block|}
DECL|method|getActivityDelegate
specifier|public
name|QtActivityDelegate
name|getActivityDelegate
parameter_list|()
block|{
return|return
name|m_activityDelegate
return|;
block|}
annotation|@
name|Override
DECL|method|onCreateInputConnection
specifier|public
name|InputConnection
name|onCreateInputConnection
parameter_list|(
name|EditorInfo
name|outAttrs
parameter_list|)
block|{
name|outAttrs
operator|.
name|inputType
operator|=
name|m_inputType
expr_stmt|;
name|outAttrs
operator|.
name|imeOptions
operator|=
name|m_imeOptions
expr_stmt|;
name|outAttrs
operator|.
name|initialCapsMode
operator|=
name|m_initialCapsMode
expr_stmt|;
name|outAttrs
operator|.
name|imeOptions
operator||=
name|EditorInfo
operator|.
name|IME_FLAG_NO_EXTRACT_UI
expr_stmt|;
return|return
operator|new
name|QtInputConnection
argument_list|(
name|this
argument_list|)
return|;
block|}
comment|// // DEBUG CODE
comment|//    @Override
comment|//    protected void onDraw(Canvas canvas) {
comment|//        canvas.drawARGB(127, 255, 0, 255);
comment|//        super.onDraw(canvas);
comment|//    }
block|}
end_class
end_unit
