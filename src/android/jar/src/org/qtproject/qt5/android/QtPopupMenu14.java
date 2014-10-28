begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the Android port of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|view
operator|.
name|MenuItem
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
name|PopupMenu
import|;
end_import
begin_class
DECL|class|QtPopupMenu14
specifier|public
class|class
name|QtPopupMenu14
block|{
DECL|method|QtPopupMenu14
specifier|private
name|QtPopupMenu14
parameter_list|()
block|{ }
DECL|class|QtPopupMenu14Holder
specifier|private
specifier|static
class|class
name|QtPopupMenu14Holder
block|{
DECL|field|INSTANCE
specifier|private
specifier|static
specifier|final
name|QtPopupMenu14
name|INSTANCE
init|=
operator|new
name|QtPopupMenu14
argument_list|()
decl_stmt|;
block|}
DECL|method|getInstance
specifier|public
specifier|static
name|QtPopupMenu14
name|getInstance
parameter_list|()
block|{
return|return
name|QtPopupMenu14Holder
operator|.
name|INSTANCE
return|;
block|}
DECL|method|showMenu
specifier|public
name|void
name|showMenu
parameter_list|(
name|View
name|anchor
parameter_list|)
block|{
name|PopupMenu
name|popup
init|=
operator|new
name|PopupMenu
argument_list|(
name|QtNative
operator|.
name|activity
argument_list|()
argument_list|,
name|anchor
argument_list|)
decl_stmt|;
name|QtNative
operator|.
name|activityDelegate
argument_list|()
operator|.
name|onCreatePopupMenu
argument_list|(
name|popup
operator|.
name|getMenu
argument_list|()
argument_list|)
expr_stmt|;
name|popup
operator|.
name|setOnMenuItemClickListener
argument_list|(
operator|new
name|PopupMenu
operator|.
name|OnMenuItemClickListener
argument_list|()
block|{
annotation|@
name|Override
specifier|public
name|boolean
name|onMenuItemClick
parameter_list|(
name|MenuItem
name|menuItem
parameter_list|)
block|{
return|return
name|QtNative
operator|.
name|activityDelegate
argument_list|()
operator|.
name|onContextItemSelected
argument_list|(
name|menuItem
argument_list|)
return|;
block|}
block|}
argument_list|)
expr_stmt|;
name|popup
operator|.
name|setOnDismissListener
argument_list|(
operator|new
name|PopupMenu
operator|.
name|OnDismissListener
argument_list|()
block|{
annotation|@
name|Override
specifier|public
name|void
name|onDismiss
parameter_list|(
name|PopupMenu
name|popupMenu
parameter_list|)
block|{
name|QtNative
operator|.
name|activityDelegate
argument_list|()
operator|.
name|onContextMenuClosed
argument_list|(
name|popupMenu
operator|.
name|getMenu
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
argument_list|)
expr_stmt|;
name|popup
operator|.
name|show
argument_list|()
expr_stmt|;
block|}
block|}
end_class
end_unit