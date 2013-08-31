begin_unit
begin_ifndef
ifndef|#
directive|ifndef
name|HB_CONFIG_H
end_ifndef
begin_define
DECL|macro|HB_CONFIG_H
define|#
directive|define
name|HB_CONFIG_H
end_define
begin_define
DECL|macro|HAVE_OT
define|#
directive|define
name|HAVE_OT
end_define
begin_define
DECL|macro|HB_NO_MT
define|#
directive|define
name|HB_NO_MT
end_define
begin_define
DECL|macro|HB_NO_UNICODE_FUNCS
define|#
directive|define
name|HB_NO_UNICODE_FUNCS
end_define
begin_define
DECL|macro|HB_DISABLE_DEPRECATED
define|#
directive|define
name|HB_DISABLE_DEPRECATED
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|HB_INTERNAL
end_ifndef
begin_define
DECL|macro|HB_INTERNAL
define|#
directive|define
name|HB_INTERNAL
value|Q_DECL_HIDDEN
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// because strdup() is not part of strict Posix, declare it here
end_comment
begin_extern
extern|extern
literal|"C"
name|char
modifier|*
name|strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|)
function_decl|;
end_extern
begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ATEXIT
end_ifndef
begin_define
DECL|macro|HAVE_ATEXIT
define|#
directive|define
name|HAVE_ATEXIT
value|1
end_define
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_define
DECL|macro|atexit
define|#
directive|define
name|atexit
value|qAddPostRoutine
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* HB_CONFIG_H */
end_comment
end_unit