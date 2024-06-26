#include "head.h"



int	main(void)
{
	char *_path = "/usr/local/rvm/gems/ruby-3.2.4/bin:/usr/local/rvm/gems/ruby-3.2.4@global/bin:/usr/local/rvm/rubies/ruby-3.2.4/bin:/vscode/bin/linux-x64/5437499feb04f7a586f677b155b039bc2b3669eb/bin/remote-cli:/home/codespace/.local/bin:/home/codespace/.dotnet:/home/codespace/nvm/current/bin:/home/codespace/.php/current/bin:/home/codespace/.python/current/bin:/home/codespace/java/current/bin:/home/codespace/.ruby/current/bin:/home/codespace/.local/bin:/usr/local/python/current/bin:/usr/local/py-utils/bin:/usr/local/oryx:/usr/local/go/bin:/go/bin:/usr/local/sdkman/bin:/usr/local/sdkman/candidates/java/current/bin:/usr/local/sdkman/candidates/gradle/current/bin:/usr/local/sdkman/candidates/maven/current/bin:/usr/local/sdkman/candidates/ant/current/bin:/usr/local/rvm/gems/default/bin:/usr/local/rvm/gems/default@global/bin:/usr/local/rvm/rubies/default/bin:/usr/local/share/rbenv/bin:/usr/local/php/current/bin:/opt/conda/bin:/usr/local/nvs:/usr/local/share/nvm/versions/node/v20.14.0/bin:/usr/local/hugo/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/share/dotnet:/home/codespace/.dotnet/tools:/usr/local/rvm/bin";
	ft_printf("Hello World\n");
	(void) _path;
	char *cmdpath = cmd_path(_path, "docker");
	ft_printf("the P_ath is : %s .\n", cmdpath);

}