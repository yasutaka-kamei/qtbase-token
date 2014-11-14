begin_unit
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_HLSL_D3DCOMPILER_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_HLSL_D3DCOMPILER_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_HLSL_D3DCOMPILER_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/Error.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"common/platform.h"
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|<string>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|InfoLog
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
struct|struct
name|CompileConfig
block|{
name|UINT
name|flags
decl_stmt|;
name|std
operator|::
name|string
name|name
expr_stmt|;
name|CompileConfig
argument_list|()
expr_stmt|;
name|CompileConfig
argument_list|(
argument|UINT flags
argument_list|,
argument|const std::string&name
argument_list|)
empty_stmt|;
block|}
struct|;
name|class
name|HLSLCompiler
block|{
name|public
label|:
name|HLSLCompiler
argument_list|()
expr_stmt|;
operator|~
name|HLSLCompiler
argument_list|()
expr_stmt|;
name|bool
name|initialize
parameter_list|()
function_decl|;
name|void
name|release
parameter_list|()
function_decl|;
comment|// Attempt to compile a HLSL shader using the supplied configurations, may output a NULL compiled blob
comment|// even if no GL errors are returned.
name|gl
operator|::
name|Error
name|compileToBinary
argument_list|(
argument|gl::InfoLog&infoLog
argument_list|,
argument|const std::string&hlsl
argument_list|,
argument|const std::string&profile
argument_list|,
argument|const std::vector<CompileConfig>&configs
argument_list|,
argument|const D3D_SHADER_MACRO *overrideMacros
argument_list|,
argument|ID3DBlob **outCompiledBlob
argument_list|,
argument|std::string *outDebugInfo
argument_list|)
specifier|const
expr_stmt|;
name|std
operator|::
name|string
name|disassembleBinary
argument_list|(
argument|ID3DBlob* shaderBinary
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|HLSLCompiler
argument_list|)
expr_stmt|;
name|HMODULE
name|mD3DCompilerModule
decl_stmt|;
name|pD3DCompile
name|mD3DCompileFunc
decl_stmt|;
name|pD3DDisassemble
name|mD3DDisassembleFunc
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_HLSL_D3DCOMPILER_H_
end_comment
end_unit
