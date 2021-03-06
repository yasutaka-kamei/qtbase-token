begin_unit
begin_comment
comment|/****************************************************************************  **  ** Copyright (C) 2016 BogDan Vatra<bogdan@kde.org>  ** Contact: https://www.qt.io/licensing/  **  ** This file is part of the Android port of the Qt Toolkit.  **  ** $QT_BEGIN_LICENSE:LGPL$  ** Commercial License Usage  ** Licensees holding valid commercial Qt licenses may use this file in  ** accordance with the commercial license agreement provided with the  ** Software or, alternatively, in accordance with the terms contained in  ** a written agreement between you and The Qt Company. For licensing terms  ** and conditions see https://www.qt.io/terms-conditions. For further  ** information use the contact form at https://www.qt.io/contact-us.  **  ** GNU Lesser General Public License Usage  ** Alternatively, this file may be used under the terms of the GNU Lesser  ** General Public License version 3 as published by the Free Software  ** Foundation and appearing in the file LICENSE.LGPL3 included in the  ** packaging of this file. Please review the following information to  ** ensure the GNU Lesser General Public License version 3 requirements  ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.  **  ** GNU General Public License Usage  ** Alternatively, this file may be used under the terms of the GNU  ** General Public License version 2.0 or (at your option) the GNU General  ** Public license version 3 or any later version approved by the KDE Free  ** Qt Foundation. The licenses are as published by the Free Software  ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3  ** included in the packaging of this file. Please review the following  ** information to ensure the GNU General Public License requirements will  ** be met: https://www.gnu.org/licenses/gpl-2.0.html and  ** https://www.gnu.org/licenses/gpl-3.0.html.  **  ** $QT_END_LICENSE$  **  ****************************************************************************/
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
name|app
operator|.
name|Activity
import|;
end_import
begin_import
import|import
name|android
operator|.
name|app
operator|.
name|AlertDialog
import|;
end_import
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
name|content
operator|.
name|DialogInterface
import|;
end_import
begin_import
import|import
name|android
operator|.
name|content
operator|.
name|res
operator|.
name|Resources
import|;
end_import
begin_import
import|import
name|android
operator|.
name|content
operator|.
name|res
operator|.
name|TypedArray
import|;
end_import
begin_import
import|import
name|android
operator|.
name|graphics
operator|.
name|drawable
operator|.
name|Drawable
import|;
end_import
begin_import
import|import
name|android
operator|.
name|os
operator|.
name|Build
import|;
end_import
begin_import
import|import
name|android
operator|.
name|text
operator|.
name|ClipboardManager
import|;
end_import
begin_import
import|import
name|android
operator|.
name|text
operator|.
name|Html
import|;
end_import
begin_import
import|import
name|android
operator|.
name|text
operator|.
name|Spanned
import|;
end_import
begin_import
import|import
name|android
operator|.
name|util
operator|.
name|TypedValue
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
name|widget
operator|.
name|Button
import|;
end_import
begin_import
import|import
name|android
operator|.
name|widget
operator|.
name|ImageView
import|;
end_import
begin_import
import|import
name|android
operator|.
name|widget
operator|.
name|LinearLayout
import|;
end_import
begin_import
import|import
name|android
operator|.
name|widget
operator|.
name|RelativeLayout
import|;
end_import
begin_import
import|import
name|android
operator|.
name|widget
operator|.
name|ScrollView
import|;
end_import
begin_import
import|import
name|android
operator|.
name|widget
operator|.
name|TextView
import|;
end_import
begin_import
import|import
name|android
operator|.
name|widget
operator|.
name|Toast
import|;
end_import
begin_import
import|import
name|java
operator|.
name|util
operator|.
name|ArrayList
import|;
end_import
begin_class
DECL|class|QtNativeDialogHelper
class|class
name|QtNativeDialogHelper
block|{
DECL|method|dialogResult
specifier|static
specifier|native
name|void
name|dialogResult
parameter_list|(
name|long
name|handler
parameter_list|,
name|int
name|buttonID
parameter_list|)
function_decl|;
block|}
end_class
begin_class
DECL|class|ButtonStruct
class|class
name|ButtonStruct
implements|implements
name|View
operator|.
name|OnClickListener
block|{
DECL|method|ButtonStruct
name|ButtonStruct
parameter_list|(
name|QtMessageDialogHelper
name|dialog
parameter_list|,
name|int
name|id
parameter_list|,
name|String
name|text
parameter_list|)
block|{
name|m_dialog
operator|=
name|dialog
expr_stmt|;
name|m_id
operator|=
name|id
expr_stmt|;
name|m_text
operator|=
name|Html
operator|.
name|fromHtml
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
DECL|field|m_dialog
name|QtMessageDialogHelper
name|m_dialog
decl_stmt|;
DECL|field|m_id
specifier|private
name|int
name|m_id
decl_stmt|;
DECL|field|m_text
name|Spanned
name|m_text
decl_stmt|;
annotation|@
name|Override
DECL|method|onClick
specifier|public
name|void
name|onClick
parameter_list|(
name|View
name|view
parameter_list|)
block|{
name|QtNativeDialogHelper
operator|.
name|dialogResult
argument_list|(
name|m_dialog
operator|.
name|handler
argument_list|()
argument_list|,
name|m_id
argument_list|)
expr_stmt|;
block|}
block|}
end_class
begin_class
DECL|class|QtMessageDialogHelper
specifier|public
class|class
name|QtMessageDialogHelper
block|{
DECL|method|QtMessageDialogHelper
specifier|public
name|QtMessageDialogHelper
parameter_list|(
name|Activity
name|activity
parameter_list|)
block|{
name|m_activity
operator|=
name|activity
expr_stmt|;
block|}
DECL|method|setIcon
specifier|public
name|void
name|setIcon
parameter_list|(
name|int
name|icon
parameter_list|)
block|{
name|m_icon
operator|=
name|icon
expr_stmt|;
block|}
DECL|method|getIconDrawable
specifier|private
name|Drawable
name|getIconDrawable
parameter_list|()
block|{
if|if
condition|(
name|m_icon
operator|==
literal|0
condition|)
return|return
literal|null
return|;
try|try
block|{
name|TypedValue
name|typedValue
init|=
operator|new
name|TypedValue
argument_list|()
decl_stmt|;
name|m_theme
operator|.
name|resolveAttribute
argument_list|(
name|android
operator|.
name|R
operator|.
name|attr
operator|.
name|alertDialogIcon
argument_list|,
name|typedValue
argument_list|,
literal|true
argument_list|)
expr_stmt|;
return|return
name|m_activity
operator|.
name|getResources
argument_list|()
operator|.
name|getDrawable
argument_list|(
name|typedValue
operator|.
name|resourceId
argument_list|)
return|;
block|}
catch|catch
parameter_list|(
name|Exception
name|e
parameter_list|)
block|{
name|e
operator|.
name|printStackTrace
argument_list|()
expr_stmt|;
block|}
comment|// Information, Warning, Critical, Question
switch|switch
condition|(
name|m_icon
condition|)
block|{
case|case
literal|1
case|:
comment|// Information
try|try
block|{
return|return
name|m_activity
operator|.
name|getResources
argument_list|()
operator|.
name|getDrawable
argument_list|(
name|android
operator|.
name|R
operator|.
name|drawable
operator|.
name|ic_dialog_info
argument_list|)
return|;
block|}
catch|catch
parameter_list|(
name|Exception
name|e
parameter_list|)
block|{
name|e
operator|.
name|printStackTrace
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
literal|2
case|:
comment|// Warning
comment|//                try {
comment|//                    return Class.forName("android.R$drawable").getDeclaredField("stat_sys_warning").getInt(null);
comment|//                } catch (Exception e) {
comment|//                    e.printStackTrace();
comment|//                }
comment|//                break;
case|case
literal|3
case|:
comment|// Critical
try|try
block|{
return|return
name|m_activity
operator|.
name|getResources
argument_list|()
operator|.
name|getDrawable
argument_list|(
name|android
operator|.
name|R
operator|.
name|drawable
operator|.
name|ic_dialog_alert
argument_list|)
return|;
block|}
catch|catch
parameter_list|(
name|Exception
name|e
parameter_list|)
block|{
name|e
operator|.
name|printStackTrace
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
literal|4
case|:
comment|// Question
try|try
block|{
return|return
name|m_activity
operator|.
name|getResources
argument_list|()
operator|.
name|getDrawable
argument_list|(
name|android
operator|.
name|R
operator|.
name|drawable
operator|.
name|ic_menu_help
argument_list|)
return|;
block|}
catch|catch
parameter_list|(
name|Exception
name|e
parameter_list|)
block|{
name|e
operator|.
name|printStackTrace
argument_list|()
expr_stmt|;
block|}
break|break;
block|}
return|return
literal|null
return|;
block|}
DECL|method|setTile
specifier|public
name|void
name|setTile
parameter_list|(
name|String
name|title
parameter_list|)
block|{
name|m_title
operator|=
name|Html
operator|.
name|fromHtml
argument_list|(
name|title
argument_list|)
expr_stmt|;
block|}
DECL|method|setText
specifier|public
name|void
name|setText
parameter_list|(
name|String
name|text
parameter_list|)
block|{
name|m_text
operator|=
name|Html
operator|.
name|fromHtml
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
DECL|method|setInformativeText
specifier|public
name|void
name|setInformativeText
parameter_list|(
name|String
name|informativeText
parameter_list|)
block|{
name|m_informativeText
operator|=
name|Html
operator|.
name|fromHtml
argument_list|(
name|informativeText
argument_list|)
expr_stmt|;
block|}
DECL|method|setDetailedText
specifier|public
name|void
name|setDetailedText
parameter_list|(
name|String
name|text
parameter_list|)
block|{
name|m_detailedText
operator|=
name|Html
operator|.
name|fromHtml
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
DECL|method|addButton
specifier|public
name|void
name|addButton
parameter_list|(
name|int
name|id
parameter_list|,
name|String
name|text
parameter_list|)
block|{
if|if
condition|(
name|m_buttonsList
operator|==
literal|null
condition|)
name|m_buttonsList
operator|=
operator|new
name|ArrayList
argument_list|<
name|ButtonStruct
argument_list|>
argument_list|()
expr_stmt|;
name|m_buttonsList
operator|.
name|add
argument_list|(
operator|new
name|ButtonStruct
argument_list|(
name|this
argument_list|,
name|id
argument_list|,
name|text
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|method|getStyledDrawable
specifier|private
name|Drawable
name|getStyledDrawable
parameter_list|(
name|String
name|drawable
parameter_list|)
throws|throws
name|ClassNotFoundException
throws|,
name|NoSuchFieldException
throws|,
name|IllegalAccessException
block|{
name|int
index|[]
name|attrs
init|=
block|{
name|Class
operator|.
name|forName
argument_list|(
literal|"android.R$attr"
argument_list|)
operator|.
name|getDeclaredField
argument_list|(
name|drawable
argument_list|)
operator|.
name|getInt
argument_list|(
literal|null
argument_list|)
block|}
decl_stmt|;
specifier|final
name|TypedArray
name|a
init|=
name|m_theme
operator|.
name|obtainStyledAttributes
argument_list|(
name|attrs
argument_list|)
decl_stmt|;
name|Drawable
name|d
init|=
name|a
operator|.
name|getDrawable
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|a
operator|.
name|recycle
argument_list|()
expr_stmt|;
return|return
name|d
return|;
block|}
DECL|method|show
specifier|public
name|void
name|show
parameter_list|(
name|long
name|handler
parameter_list|)
block|{
name|m_handler
operator|=
name|handler
expr_stmt|;
name|m_activity
operator|.
name|runOnUiThread
argument_list|(
operator|new
name|Runnable
argument_list|()
block|{
annotation|@
name|Override
specifier|public
name|void
name|run
parameter_list|()
block|{
if|if
condition|(
name|m_dialog
operator|!=
literal|null
operator|&&
name|m_dialog
operator|.
name|isShowing
argument_list|()
condition|)
name|m_dialog
operator|.
name|dismiss
argument_list|()
expr_stmt|;
name|m_dialog
operator|=
operator|new
name|AlertDialog
operator|.
name|Builder
argument_list|(
name|m_activity
argument_list|)
operator|.
name|create
argument_list|()
expr_stmt|;
name|m_theme
operator|=
name|m_dialog
operator|.
name|getWindow
argument_list|()
operator|.
name|getContext
argument_list|()
operator|.
name|getTheme
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_title
operator|!=
literal|null
condition|)
name|m_dialog
operator|.
name|setTitle
argument_list|(
name|m_title
argument_list|)
expr_stmt|;
name|m_dialog
operator|.
name|setOnCancelListener
argument_list|(
operator|new
name|DialogInterface
operator|.
name|OnCancelListener
argument_list|()
block|{
annotation|@
name|Override
specifier|public
name|void
name|onCancel
parameter_list|(
name|DialogInterface
name|dialogInterface
parameter_list|)
block|{
name|QtNativeDialogHelper
operator|.
name|dialogResult
argument_list|(
name|handler
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
argument_list|)
expr_stmt|;
name|m_dialog
operator|.
name|setCancelable
argument_list|(
name|m_buttonsList
operator|==
literal|null
argument_list|)
expr_stmt|;
name|m_dialog
operator|.
name|setCanceledOnTouchOutside
argument_list|(
name|m_buttonsList
operator|==
literal|null
argument_list|)
expr_stmt|;
name|m_dialog
operator|.
name|setIcon
argument_list|(
name|getIconDrawable
argument_list|()
argument_list|)
expr_stmt|;
name|ScrollView
name|scrollView
init|=
operator|new
name|ScrollView
argument_list|(
name|m_activity
argument_list|)
decl_stmt|;
name|RelativeLayout
name|dialogLayout
init|=
operator|new
name|RelativeLayout
argument_list|(
name|m_activity
argument_list|)
decl_stmt|;
name|int
name|id
init|=
literal|1
decl_stmt|;
name|View
name|lastView
init|=
literal|null
decl_stmt|;
name|View
operator|.
name|OnLongClickListener
name|copyText
init|=
operator|new
name|View
operator|.
name|OnLongClickListener
argument_list|()
block|{
annotation|@
name|Override
specifier|public
name|boolean
name|onLongClick
parameter_list|(
name|View
name|view
parameter_list|)
block|{
name|TextView
name|tv
init|=
operator|(
name|TextView
operator|)
name|view
decl_stmt|;
if|if
condition|(
name|tv
operator|!=
literal|null
condition|)
block|{
name|ClipboardManager
name|cm
init|=
operator|(
name|android
operator|.
name|text
operator|.
name|ClipboardManager
operator|)
name|m_activity
operator|.
name|getSystemService
argument_list|(
name|Context
operator|.
name|CLIPBOARD_SERVICE
argument_list|)
decl_stmt|;
name|cm
operator|.
name|setText
argument_list|(
name|tv
operator|.
name|getText
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
block|}
decl_stmt|;
if|if
condition|(
name|m_text
operator|!=
literal|null
condition|)
block|{
name|TextView
name|view
init|=
operator|new
name|TextView
argument_list|(
name|m_activity
argument_list|)
decl_stmt|;
name|view
operator|.
name|setId
argument_list|(
name|id
operator|++
argument_list|)
expr_stmt|;
name|view
operator|.
name|setOnLongClickListener
argument_list|(
name|copyText
argument_list|)
expr_stmt|;
name|view
operator|.
name|setLongClickable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|view
operator|.
name|setText
argument_list|(
name|m_text
argument_list|)
expr_stmt|;
name|view
operator|.
name|setTextAppearance
argument_list|(
name|m_activity
argument_list|,
name|android
operator|.
name|R
operator|.
name|style
operator|.
name|TextAppearance_Medium
argument_list|)
expr_stmt|;
name|RelativeLayout
operator|.
name|LayoutParams
name|layout
init|=
operator|new
name|RelativeLayout
operator|.
name|LayoutParams
argument_list|(
name|RelativeLayout
operator|.
name|LayoutParams
operator|.
name|MATCH_PARENT
argument_list|,
name|RelativeLayout
operator|.
name|LayoutParams
operator|.
name|WRAP_CONTENT
argument_list|)
decl_stmt|;
name|layout
operator|.
name|setMargins
argument_list|(
literal|16
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|layout
operator|.
name|addRule
argument_list|(
name|RelativeLayout
operator|.
name|ALIGN_PARENT_TOP
argument_list|)
expr_stmt|;
name|dialogLayout
operator|.
name|addView
argument_list|(
name|view
argument_list|,
name|layout
argument_list|)
expr_stmt|;
name|lastView
operator|=
name|view
expr_stmt|;
block|}
if|if
condition|(
name|m_informativeText
operator|!=
literal|null
condition|)
block|{
name|TextView
name|view
init|=
operator|new
name|TextView
argument_list|(
name|m_activity
argument_list|)
decl_stmt|;
name|view
operator|.
name|setId
argument_list|(
name|id
operator|++
argument_list|)
expr_stmt|;
name|view
operator|.
name|setOnLongClickListener
argument_list|(
name|copyText
argument_list|)
expr_stmt|;
name|view
operator|.
name|setLongClickable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|view
operator|.
name|setText
argument_list|(
name|m_informativeText
argument_list|)
expr_stmt|;
name|view
operator|.
name|setTextAppearance
argument_list|(
name|m_activity
argument_list|,
name|android
operator|.
name|R
operator|.
name|style
operator|.
name|TextAppearance_Medium
argument_list|)
expr_stmt|;
name|RelativeLayout
operator|.
name|LayoutParams
name|layout
init|=
operator|new
name|RelativeLayout
operator|.
name|LayoutParams
argument_list|(
name|RelativeLayout
operator|.
name|LayoutParams
operator|.
name|MATCH_PARENT
argument_list|,
name|RelativeLayout
operator|.
name|LayoutParams
operator|.
name|WRAP_CONTENT
argument_list|)
decl_stmt|;
name|layout
operator|.
name|setMargins
argument_list|(
literal|16
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|,
literal|8
argument_list|)
expr_stmt|;
if|if
condition|(
name|lastView
operator|!=
literal|null
condition|)
name|layout
operator|.
name|addRule
argument_list|(
name|RelativeLayout
operator|.
name|BELOW
argument_list|,
name|lastView
operator|.
name|getId
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|layout
operator|.
name|addRule
argument_list|(
name|RelativeLayout
operator|.
name|ALIGN_PARENT_TOP
argument_list|)
expr_stmt|;
name|dialogLayout
operator|.
name|addView
argument_list|(
name|view
argument_list|,
name|layout
argument_list|)
expr_stmt|;
name|lastView
operator|=
name|view
expr_stmt|;
block|}
if|if
condition|(
name|m_detailedText
operator|!=
literal|null
condition|)
block|{
name|TextView
name|view
init|=
operator|new
name|TextView
argument_list|(
name|m_activity
argument_list|)
decl_stmt|;
name|view
operator|.
name|setId
argument_list|(
name|id
operator|++
argument_list|)
expr_stmt|;
name|view
operator|.
name|setOnLongClickListener
argument_list|(
name|copyText
argument_list|)
expr_stmt|;
name|view
operator|.
name|setLongClickable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|view
operator|.
name|setText
argument_list|(
name|m_detailedText
argument_list|)
expr_stmt|;
name|view
operator|.
name|setTextAppearance
argument_list|(
name|m_activity
argument_list|,
name|android
operator|.
name|R
operator|.
name|style
operator|.
name|TextAppearance_Small
argument_list|)
expr_stmt|;
name|RelativeLayout
operator|.
name|LayoutParams
name|layout
init|=
operator|new
name|RelativeLayout
operator|.
name|LayoutParams
argument_list|(
name|RelativeLayout
operator|.
name|LayoutParams
operator|.
name|MATCH_PARENT
argument_list|,
name|RelativeLayout
operator|.
name|LayoutParams
operator|.
name|WRAP_CONTENT
argument_list|)
decl_stmt|;
name|layout
operator|.
name|setMargins
argument_list|(
literal|16
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|,
literal|8
argument_list|)
expr_stmt|;
if|if
condition|(
name|lastView
operator|!=
literal|null
condition|)
name|layout
operator|.
name|addRule
argument_list|(
name|RelativeLayout
operator|.
name|BELOW
argument_list|,
name|lastView
operator|.
name|getId
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|layout
operator|.
name|addRule
argument_list|(
name|RelativeLayout
operator|.
name|ALIGN_PARENT_TOP
argument_list|)
expr_stmt|;
name|dialogLayout
operator|.
name|addView
argument_list|(
name|view
argument_list|,
name|layout
argument_list|)
expr_stmt|;
name|lastView
operator|=
name|view
expr_stmt|;
block|}
if|if
condition|(
name|m_buttonsList
operator|!=
literal|null
condition|)
block|{
name|LinearLayout
name|buttonsLayout
init|=
operator|new
name|LinearLayout
argument_list|(
name|m_activity
argument_list|)
decl_stmt|;
name|buttonsLayout
operator|.
name|setOrientation
argument_list|(
name|LinearLayout
operator|.
name|HORIZONTAL
argument_list|)
expr_stmt|;
name|buttonsLayout
operator|.
name|setId
argument_list|(
name|id
operator|++
argument_list|)
expr_stmt|;
name|boolean
name|firstButton
init|=
literal|true
decl_stmt|;
for|for
control|(
name|ButtonStruct
name|button
range|:
name|m_buttonsList
control|)
block|{
name|Button
name|bv
decl_stmt|;
try|try
block|{
name|bv
operator|=
operator|new
name|Button
argument_list|(
name|m_activity
argument_list|,
literal|null
argument_list|,
name|Class
operator|.
name|forName
argument_list|(
literal|"android.R$attr"
argument_list|)
operator|.
name|getDeclaredField
argument_list|(
literal|"borderlessButtonStyle"
argument_list|)
operator|.
name|getInt
argument_list|(
literal|null
argument_list|)
argument_list|)
expr_stmt|;
block|}
catch|catch
parameter_list|(
name|Exception
name|e
parameter_list|)
block|{
name|bv
operator|=
operator|new
name|Button
argument_list|(
name|m_activity
argument_list|)
expr_stmt|;
name|e
operator|.
name|printStackTrace
argument_list|()
expr_stmt|;
block|}
name|bv
operator|.
name|setText
argument_list|(
name|button
operator|.
name|m_text
argument_list|)
expr_stmt|;
name|bv
operator|.
name|setOnClickListener
argument_list|(
name|button
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|firstButton
condition|)
comment|// first button
block|{
name|LinearLayout
operator|.
name|LayoutParams
name|layout
init|=
literal|null
decl_stmt|;
name|View
name|spacer
init|=
operator|new
name|View
argument_list|(
name|m_activity
argument_list|)
decl_stmt|;
try|try
block|{
name|layout
operator|=
operator|new
name|LinearLayout
operator|.
name|LayoutParams
argument_list|(
literal|1
argument_list|,
name|RelativeLayout
operator|.
name|LayoutParams
operator|.
name|MATCH_PARENT
argument_list|)
expr_stmt|;
name|spacer
operator|.
name|setBackgroundDrawable
argument_list|(
name|getStyledDrawable
argument_list|(
literal|"dividerVertical"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonsLayout
operator|.
name|addView
argument_list|(
name|spacer
argument_list|,
name|layout
argument_list|)
expr_stmt|;
block|}
catch|catch
parameter_list|(
name|Exception
name|e
parameter_list|)
block|{
name|e
operator|.
name|printStackTrace
argument_list|()
expr_stmt|;
block|}
block|}
name|LinearLayout
operator|.
name|LayoutParams
name|layout
init|=
literal|null
decl_stmt|;
name|layout
operator|=
operator|new
name|LinearLayout
operator|.
name|LayoutParams
argument_list|(
name|RelativeLayout
operator|.
name|LayoutParams
operator|.
name|MATCH_PARENT
argument_list|,
name|RelativeLayout
operator|.
name|LayoutParams
operator|.
name|WRAP_CONTENT
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|buttonsLayout
operator|.
name|addView
argument_list|(
name|bv
argument_list|,
name|layout
argument_list|)
expr_stmt|;
name|firstButton
operator|=
literal|false
expr_stmt|;
block|}
try|try
block|{
name|View
name|horizontalDevider
init|=
operator|new
name|View
argument_list|(
name|m_activity
argument_list|)
decl_stmt|;
name|horizontalDevider
operator|.
name|setId
argument_list|(
name|id
operator|++
argument_list|)
expr_stmt|;
name|horizontalDevider
operator|.
name|setBackgroundDrawable
argument_list|(
name|getStyledDrawable
argument_list|(
literal|"dividerHorizontal"
argument_list|)
argument_list|)
expr_stmt|;
name|RelativeLayout
operator|.
name|LayoutParams
name|relativeParams
init|=
operator|new
name|RelativeLayout
operator|.
name|LayoutParams
argument_list|(
name|RelativeLayout
operator|.
name|LayoutParams
operator|.
name|MATCH_PARENT
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|relativeParams
operator|.
name|setMargins
argument_list|(
literal|0
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|lastView
operator|!=
literal|null
condition|)
block|{
name|relativeParams
operator|.
name|addRule
argument_list|(
name|RelativeLayout
operator|.
name|BELOW
argument_list|,
name|lastView
operator|.
name|getId
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
name|relativeParams
operator|.
name|addRule
argument_list|(
name|RelativeLayout
operator|.
name|ALIGN_PARENT_TOP
argument_list|)
expr_stmt|;
name|dialogLayout
operator|.
name|addView
argument_list|(
name|horizontalDevider
argument_list|,
name|relativeParams
argument_list|)
expr_stmt|;
name|lastView
operator|=
name|horizontalDevider
expr_stmt|;
block|}
catch|catch
parameter_list|(
name|Exception
name|e
parameter_list|)
block|{
name|e
operator|.
name|printStackTrace
argument_list|()
expr_stmt|;
block|}
name|RelativeLayout
operator|.
name|LayoutParams
name|relativeParams
init|=
operator|new
name|RelativeLayout
operator|.
name|LayoutParams
argument_list|(
name|RelativeLayout
operator|.
name|LayoutParams
operator|.
name|MATCH_PARENT
argument_list|,
name|RelativeLayout
operator|.
name|LayoutParams
operator|.
name|WRAP_CONTENT
argument_list|)
decl_stmt|;
if|if
condition|(
name|lastView
operator|!=
literal|null
condition|)
block|{
name|relativeParams
operator|.
name|addRule
argument_list|(
name|RelativeLayout
operator|.
name|BELOW
argument_list|,
name|lastView
operator|.
name|getId
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
name|relativeParams
operator|.
name|addRule
argument_list|(
name|RelativeLayout
operator|.
name|ALIGN_PARENT_TOP
argument_list|)
expr_stmt|;
name|relativeParams
operator|.
name|setMargins
argument_list|(
literal|2
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|dialogLayout
operator|.
name|addView
argument_list|(
name|buttonsLayout
argument_list|,
name|relativeParams
argument_list|)
expr_stmt|;
block|}
name|scrollView
operator|.
name|addView
argument_list|(
name|dialogLayout
argument_list|)
expr_stmt|;
name|m_dialog
operator|.
name|setView
argument_list|(
name|scrollView
argument_list|)
expr_stmt|;
name|m_dialog
operator|.
name|show
argument_list|()
expr_stmt|;
block|}
block|}
argument_list|)
expr_stmt|;
block|}
DECL|method|hide
specifier|public
name|void
name|hide
parameter_list|()
block|{
name|m_activity
operator|.
name|runOnUiThread
argument_list|(
operator|new
name|Runnable
argument_list|()
block|{
annotation|@
name|Override
specifier|public
name|void
name|run
parameter_list|()
block|{
if|if
condition|(
name|m_dialog
operator|!=
literal|null
operator|&&
name|m_dialog
operator|.
name|isShowing
argument_list|()
condition|)
name|m_dialog
operator|.
name|dismiss
argument_list|()
expr_stmt|;
name|reset
argument_list|()
expr_stmt|;
block|}
block|}
argument_list|)
expr_stmt|;
block|}
DECL|method|handler
specifier|public
name|long
name|handler
parameter_list|()
block|{
return|return
name|m_handler
return|;
block|}
DECL|method|reset
specifier|public
name|void
name|reset
parameter_list|()
block|{
name|m_icon
operator|=
literal|0
expr_stmt|;
name|m_title
operator|=
literal|null
expr_stmt|;
name|m_text
operator|=
literal|null
expr_stmt|;
name|m_informativeText
operator|=
literal|null
expr_stmt|;
name|m_detailedText
operator|=
literal|null
expr_stmt|;
name|m_buttonsList
operator|=
literal|null
expr_stmt|;
name|m_dialog
operator|=
literal|null
expr_stmt|;
name|m_handler
operator|=
literal|0
expr_stmt|;
block|}
DECL|field|m_activity
specifier|private
name|Activity
name|m_activity
decl_stmt|;
DECL|field|m_icon
specifier|private
name|int
name|m_icon
init|=
literal|0
decl_stmt|;
DECL|field|m_title
DECL|field|m_text
DECL|field|m_informativeText
DECL|field|m_detailedText
specifier|private
name|Spanned
name|m_title
decl_stmt|,
name|m_text
decl_stmt|,
name|m_informativeText
decl_stmt|,
name|m_detailedText
decl_stmt|;
DECL|field|m_buttonsList
specifier|private
name|ArrayList
argument_list|<
name|ButtonStruct
argument_list|>
name|m_buttonsList
decl_stmt|;
DECL|field|m_dialog
specifier|private
name|AlertDialog
name|m_dialog
decl_stmt|;
DECL|field|m_handler
specifier|private
name|long
name|m_handler
init|=
literal|0
decl_stmt|;
DECL|field|m_theme
specifier|private
name|Resources
operator|.
name|Theme
name|m_theme
decl_stmt|;
block|}
end_class
end_unit
