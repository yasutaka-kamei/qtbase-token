begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2012 Klaralvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Christoph Schleifenbaum<christoph.schleifenbaum@kdab.com> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformsystemtrayicon.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QPlatformSystemTrayIcon     \inmodule QtGui     \brief The QPlatformSystemTrayIcon class abstracts the system tray icon and interaction.      \sa QSystemTrayIcon */
comment|/*!     \enum QPlatformSystemTrayIcon::MessageIcon      This enum describes the icon that is shown when a balloon message is displayed.      \value NoIcon      No icon is shown.     \value Information An information icon is shown.     \value Warning     A standard warning icon is shown.     \value Critical    A critical warning icon is shown.      \sa updateIcon(), showMessage(), QMessageBox */
comment|/*!     \enum QPlatformSystemTrayIcon::ActivationReason       This enum describes the reason the system tray was activated.       \value Unknown     Unknown reason      \value Context     The context menu for the system tray entry was requested      \value DoubleClick The system tray entry was double clicked      \value Trigger     The system tray entry was clicked      \value MiddleClick The system tray entry was clicked with the middle mouse button       \sa activated() */
comment|/*!     \internal  */
DECL|function|QPlatformSystemTrayIcon
name|QPlatformSystemTrayIcon
operator|::
name|QPlatformSystemTrayIcon
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     \internal  */
end_comment
begin_destructor
DECL|function|~QPlatformSystemTrayIcon
name|QPlatformSystemTrayIcon
operator|::
name|~
name|QPlatformSystemTrayIcon
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \fn void QPlatformSystemTrayIcon::init()     This method is called to initialize the platform dependent implementation. */
end_comment
begin_comment
comment|/*!     \fn void QPlatformSystemTrayIcon::cleanup()     This method is called to cleanup the platform dependent implementation. */
end_comment
begin_comment
comment|/*!     \fn void QPlatformSystemTrayIcon::updateIcon(const QIcon&icon)     This method is called when the \a icon did change. */
end_comment
begin_comment
comment|/*!     \fn void QPlatformSystemTrayIcon::updateToolTip(const QString&tooltip)     This method is called when the \a tooltip text did change. */
end_comment
begin_comment
comment|/*!     \fn void QPlatformSystemTrayIcon::updateMenu(QPlatformMenu *menu)     This method is called when the system tray \a menu did change. */
end_comment
begin_comment
comment|/*!     \fn QRect QPlatformSystemTrayIcon::geometry() const     This method returns the geometry of the platform dependent system tray icon on the screen. */
end_comment
begin_comment
comment|/*!     \fn void QPlatformSystemTrayIcon::showMessage(const QString&title, const QString&msg,                                                   const QIcon&icon, MessageIcon iconType, int msecs)     Shows a balloon message for the entry with the given \a title, message \a msg and \a icon for     the time specified in \a msecs. \a iconType is used as a hint for the implementing platform.     \sa QSystemTrayIcon::showMessage() */
end_comment
begin_comment
comment|/*!     \fn bool QPlatformSystemTrayIcon::isSystemTrayAvailable() const     Returns \c true if the system tray is available on the platform. */
end_comment
begin_comment
comment|/*!     \fn bool QPlatformSystemTrayIcon::supportsMessages() const     Returns \c true if the system tray supports messages on the platform. */
end_comment
begin_comment
comment|/*!     \fn void QPlatformSystemTrayIcon::activated(QPlatformSystemTrayIcon::ActivationReason reason)     This signal is emitted when the user activates the system tray icon.     \a reason specifies the reason for activation.     \sa QSystemTrayIcon::ActivationReason */
end_comment
begin_comment
comment|/*!     \fn void QPlatformSystemTrayIcon::messageClicked()      This signal is emitted when the message displayed using showMessage()     was clicked by the user.      \sa activated() */
end_comment
begin_comment
comment|/*!     This method is called in case there is no QPlatformMenu available when     updating the menu. This allows the abstraction to provide a menu for the     system tray icon even if normally a non-native menu is used.      The default implementation returns a null pointer.      \sa updateMenu()     \since 5.3  */
end_comment
begin_function
DECL|function|createMenu
name|QPlatformMenu
modifier|*
name|QPlatformSystemTrayIcon
operator|::
name|createMenu
parameter_list|()
specifier|const
block|{
return|return
name|Q_NULLPTR
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qplatformsystemtrayicon.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SYSTEMTRAYICON
end_comment
end_unit
