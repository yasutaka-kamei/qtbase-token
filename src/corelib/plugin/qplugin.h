begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLUGIN_H
end_ifndef
begin_define
DECL|macro|QPLUGIN_H
define|#
directive|define
name|QPLUGIN_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qjsonobject.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|Q_EXTERN_C
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|Q_EXTERN_C
define|#
directive|define
name|Q_EXTERN_C
value|extern "C"
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|Q_EXTERN_C
value|extern
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|QtPluginInstanceFunction
typedef|typedef
name|QObject
modifier|*
function_decl|(
modifier|*
name|QtPluginInstanceFunction
function_decl|)
parameter_list|()
function_decl|;
end_typedef
begin_typedef
DECL|typedef|QtPluginMetaDataFunction
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|QtPluginMetaDataFunction
function_decl|)
parameter_list|()
function_decl|;
end_typedef
begin_struct
DECL|struct|QStaticPlugin
struct|struct
name|Q_CORE_EXPORT
name|QStaticPlugin
block|{
comment|// Note: This struct is initialized using an initializer list.
comment|// As such, it cannot have any new constructors or variables.
ifndef|#
directive|ifndef
name|Q_QDOC
DECL|member|instance
name|QtPluginInstanceFunction
name|instance
decl_stmt|;
DECL|member|rawMetaData
name|QtPluginMetaDataFunction
name|rawMetaData
decl_stmt|;
else|#
directive|else
comment|// Since qdoc gets confused by the use of function
comment|// pointers, we add these dummes for it to parse instead:
name|QObject
modifier|*
name|instance
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|rawMetaData
parameter_list|()
function_decl|;
endif|#
directive|endif
name|QJsonObject
name|metaData
argument_list|()
specifier|const
expr_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QStaticPlugin
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|Q_CORE_EXPORT
name|qRegisterStaticPluginFunction
parameter_list|(
name|QStaticPlugin
name|staticPlugin
parameter_list|)
function_decl|;
end_function_decl
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|Q_OF_ELF
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|)
operator|&&
operator|(
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_CC_CLANG
argument_list|)
operator|)
end_if
begin_define
DECL|macro|QT_PLUGIN_METADATA_SECTION
define|#
directive|define
name|QT_PLUGIN_METADATA_SECTION
define|\
value|__attribute__ ((section (".qtmetadata"))) __attribute__((used))
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_elif
begin_comment
comment|// TODO: Implement section parsing on Mac
end_comment
begin_define
DECL|macro|QT_PLUGIN_METADATA_SECTION
define|#
directive|define
name|QT_PLUGIN_METADATA_SECTION
define|\
value|__attribute__ ((section ("__TEXT,qtmetadata"))) __attribute__((used))
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
end_elif
begin_comment
comment|// TODO: Implement section parsing for MSVC
end_comment
begin_pragma
pragma|#
directive|pragma
name|section
name|(
literal|".qtmetadata"
name|,
name|read
name|,
name|shared
name|)
end_pragma
begin_define
DECL|macro|QT_PLUGIN_METADATA_SECTION
define|#
directive|define
name|QT_PLUGIN_METADATA_SECTION
define|\
value|__declspec(allocate(".qtmetadata"))
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_PLUGIN_VERIFICATION_SECTION
define|#
directive|define
name|QT_PLUGIN_VERIFICATION_SECTION
end_define
begin_define
DECL|macro|QT_PLUGIN_METADATA_SECTION
define|#
directive|define
name|QT_PLUGIN_METADATA_SECTION
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|Q_IMPORT_PLUGIN
define|#
directive|define
name|Q_IMPORT_PLUGIN
parameter_list|(
name|PLUGIN
parameter_list|)
define|\
value|extern const QT_PREPEND_NAMESPACE(QStaticPlugin) qt_static_plugin_##PLUGIN(); \         class Static##PLUGIN##PluginInstance{ \         public: \                 Static##PLUGIN##PluginInstance() { \                     qRegisterStaticPluginFunction(qt_static_plugin_##PLUGIN()); \                 } \         }; \        static Static##PLUGIN##PluginInstance static##PLUGIN##Instance;
end_define
begin_define
DECL|macro|Q_PLUGIN_INSTANCE
define|#
directive|define
name|Q_PLUGIN_INSTANCE
parameter_list|(
name|IMPLEMENTATION
parameter_list|)
define|\
value|{ \             static QT_PREPEND_NAMESPACE(QPointer)<QT_PREPEND_NAMESPACE(QObject)> _instance; \             if (!_instance)      \                 _instance = new IMPLEMENTATION; \             return _instance; \         }
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_STATICPLUGIN
argument_list|)
end_if
begin_define
DECL|macro|QT_MOC_EXPORT_PLUGIN
define|#
directive|define
name|QT_MOC_EXPORT_PLUGIN
parameter_list|(
name|PLUGINCLASS
parameter_list|,
name|PLUGINCLASSNAME
parameter_list|)
define|\
value|static QT_PREPEND_NAMESPACE(QObject) *qt_plugin_instance_##PLUGINCLASSNAME() \     Q_PLUGIN_INSTANCE(PLUGINCLASS) \     static const char *qt_plugin_query_metadata_##PLUGINCLASSNAME() { return reinterpret_cast<const char *>(qt_pluginMetaData); } \     const QT_PREPEND_NAMESPACE(QStaticPlugin) qt_static_plugin_##PLUGINCLASSNAME() { \         QT_PREPEND_NAMESPACE(QStaticPlugin) plugin = { qt_plugin_instance_##PLUGINCLASSNAME, qt_plugin_query_metadata_##PLUGINCLASSNAME}; \         return plugin; \     }
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_MOC_EXPORT_PLUGIN
define|#
directive|define
name|QT_MOC_EXPORT_PLUGIN
parameter_list|(
name|PLUGINCLASS
parameter_list|,
name|PLUGINCLASSNAME
parameter_list|)
define|\
value|Q_EXTERN_C Q_DECL_EXPORT \             const char *qt_plugin_query_metadata() \             { return reinterpret_cast<const char *>(qt_pluginMetaData); } \             Q_EXTERN_C Q_DECL_EXPORT QT_PREPEND_NAMESPACE(QObject) *qt_plugin_instance() \             Q_PLUGIN_INSTANCE(PLUGINCLASS)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|Q_EXPORT_PLUGIN
define|#
directive|define
name|Q_EXPORT_PLUGIN
parameter_list|(
name|PLUGIN
parameter_list|)
define|\
value|Q_EXPORT_PLUGIN2(PLUGIN, PLUGIN)
end_define
begin_define
DECL|macro|Q_EXPORT_PLUGIN2
define|#
directive|define
name|Q_EXPORT_PLUGIN2
parameter_list|(
name|PLUGIN
parameter_list|,
name|PLUGINCLASS
parameter_list|)
define|\
value|Q_STATIC_ASSERT_X(false, "Old plugin system used")
end_define
begin_define
DECL|macro|Q_EXPORT_STATIC_PLUGIN2
define|#
directive|define
name|Q_EXPORT_STATIC_PLUGIN2
parameter_list|(
name|PLUGIN
parameter_list|,
name|PLUGINCLASS
parameter_list|)
define|\
value|Q_STATIC_ASSERT_X(false, "Old plugin system used")
end_define
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_PLUGIN_H
end_comment
end_unit
