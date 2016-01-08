begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBKEYBOARD_H
end_ifndef
begin_define
DECL|macro|QXCBKEYBOARD_H
define|#
directive|define
name|QXCBKEYBOARD_H
end_define
begin_include
include|#
directive|include
file|"qxcbobject.h"
end_include
begin_include
include|#
directive|include
file|<xcb/xcb_keysyms.h>
end_include
begin_include
include|#
directive|include
file|<xkbcommon/xkbcommon.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XKB
end_ifndef
begin_include
include|#
directive|include
file|<xkbcommon/xkbcommon-x11.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QEvent>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QXcbKeyboard
range|:
name|public
name|QXcbObject
block|{
name|public
operator|:
name|QXcbKeyboard
argument_list|(
name|QXcbConnection
operator|*
name|connection
argument_list|)
block|;
operator|~
name|QXcbKeyboard
argument_list|()
block|;
name|void
name|handleKeyPressEvent
argument_list|(
specifier|const
name|xcb_key_press_event_t
operator|*
name|event
argument_list|)
block|;
name|void
name|handleKeyReleaseEvent
argument_list|(
specifier|const
name|xcb_key_release_event_t
operator|*
name|event
argument_list|)
block|;
name|void
name|handleMappingNotifyEvent
argument_list|(
specifier|const
name|void
operator|*
name|event
argument_list|)
block|;
name|Qt
operator|::
name|KeyboardModifiers
name|translateModifiers
argument_list|(
argument|int s
argument_list|)
specifier|const
block|;
name|void
name|updateKeymap
argument_list|()
block|;
name|QList
operator|<
name|int
operator|>
name|possibleKeys
argument_list|(
argument|const QKeyEvent *e
argument_list|)
specifier|const
block|;
comment|// when XKEYBOARD not present on the X server
name|void
name|updateXKBMods
argument_list|()
block|;
name|quint32
name|xkbModMask
argument_list|(
argument|quint16 state
argument_list|)
block|;
name|void
name|updateXKBStateFromCore
argument_list|(
argument|quint16 state
argument_list|)
block|;
ifdef|#
directive|ifdef
name|XCB_USE_XINPUT22
name|void
name|updateXKBStateFromXI
argument_list|(
name|void
operator|*
name|modInfo
argument_list|,
name|void
operator|*
name|groupInfo
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_XKB
comment|// when XKEYBOARD is present on the X server
name|int
name|coreDeviceId
argument_list|()
specifier|const
block|{
return|return
name|core_device_id
return|;
block|}
name|void
name|updateXKBState
argument_list|(
name|xcb_xkb_state_notify_event_t
operator|*
name|state
argument_list|)
block|;
endif|#
directive|endif
name|protected
operator|:
name|void
name|handleKeyEvent
argument_list|(
argument|xcb_window_t sourceWindow
argument_list|,
argument|QEvent::Type type
argument_list|,
argument|xcb_keycode_t code
argument_list|,
argument|quint16 state
argument_list|,
argument|xcb_timestamp_t time
argument_list|)
block|;
name|void
name|resolveMaskConflicts
argument_list|()
block|;
name|QString
name|lookupString
argument_list|(
argument|struct xkb_state *state
argument_list|,
argument|xcb_keycode_t code
argument_list|)
specifier|const
block|;
name|int
name|keysymToQtKey
argument_list|(
argument|xcb_keysym_t keysym
argument_list|)
specifier|const
block|;
name|int
name|keysymToQtKey
argument_list|(
argument|xcb_keysym_t keysym
argument_list|,
argument|Qt::KeyboardModifiers&modifiers
argument_list|,
argument|const QString&text
argument_list|)
specifier|const
block|;
name|void
name|printKeymapError
argument_list|(
argument|const char *error
argument_list|)
specifier|const
block|;
name|void
name|readXKBConfig
argument_list|()
block|;
name|void
name|clearXKBConfig
argument_list|()
block|;
comment|// when XKEYBOARD not present on the X server
name|void
name|updateModifiers
argument_list|()
block|;
comment|// when XKEYBOARD is present on the X server
name|void
name|updateVModMapping
argument_list|()
block|;
name|void
name|updateVModToRModMapping
argument_list|()
block|;
name|xkb_keysym_t
name|lookupLatinKeysym
argument_list|(
argument|xkb_keycode_t keycode
argument_list|)
specifier|const
block|;
name|void
name|checkForLatinLayout
argument_list|()
block|;
name|private
operator|:
name|bool
name|m_config
block|;
name|xcb_keycode_t
name|m_autorepeat_code
block|;      struct
name|xkb_context
operator|*
name|xkb_context
block|;     struct
name|xkb_keymap
operator|*
name|xkb_keymap
block|;     struct
name|xkb_state
operator|*
name|xkb_state
block|;     struct
name|xkb_rule_names
name|xkb_names
block|;
name|mutable
expr|struct
name|xkb_keymap
operator|*
name|latin_keymap
block|;      struct
name|_mod_masks
block|{
name|uint
name|alt
block|;
name|uint
name|altgr
block|;
name|uint
name|meta
block|;
name|uint
name|super
block|;
name|uint
name|hyper
block|;     }
block|;
name|_mod_masks
name|rmod_masks
block|;
comment|// when XKEYBOARD not present on the X server
name|xcb_key_symbols_t
operator|*
name|m_key_symbols
block|;     struct
name|_xkb_mods
block|{
name|xkb_mod_index_t
name|shift
block|;
name|xkb_mod_index_t
name|lock
block|;
name|xkb_mod_index_t
name|control
block|;
name|xkb_mod_index_t
name|mod1
block|;
name|xkb_mod_index_t
name|mod2
block|;
name|xkb_mod_index_t
name|mod3
block|;
name|xkb_mod_index_t
name|mod4
block|;
name|xkb_mod_index_t
name|mod5
block|;     }
block|;
name|_xkb_mods
name|xkb_mods
block|;
ifndef|#
directive|ifndef
name|QT_NO_XKB
comment|// when XKEYBOARD is present on the X server
name|_mod_masks
name|vmod_masks
block|;
name|int
name|core_device_id
block|;
endif|#
directive|endif
name|bool
name|m_hasLatinLayout
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
