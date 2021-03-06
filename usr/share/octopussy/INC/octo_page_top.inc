<% 
my %arg = @_; 
use AAT;

if ((NULL($Session->{AAT_LOGIN})) 
	|| ($Session->{AAT_ROLE} eq "restricted"))
{	
	my $page = "./login.asp?redirect=" 
		. $Request->ServerVariables("REQUEST_URI");
	$Response->Redirect($page);
}
my $title = "Octopussy " . (AAT::Translation($arg{title}) || "");
if (defined $arg{refresh})
{
  %><AAT:PageTop title="$title" icon="IMG/octo_login1.png" onLoad="$arg{onLoad}"
  refresh="$arg{refresh}" close_popup="y" popup="y" tooltip="y" /><%
}
elsif (defined $arg{ofc})
{
   %><AAT:PageTop title="$title" icon="IMG/octopussy.gif" ofc="$arg{ofc}"
  close_popup="y" popup="y" tooltip="y" onLoad="$arg{onLoad}" /><%
}
else
{
  %><AAT:PageTop title="$title" icon="IMG/octopussy.gif"
  close_popup="y" popup="y" tooltip="y" onLoad="$arg{onLoad}" /><%
}%>
<table cellpadding="0" cellspacing="0" border="0" width="100%">
<tr><td colspan="2"><% $Response->Include('INC/octo_top_menu.inc', help => $arg{help}) %></td></tr>
<tr>
<td valign="top"><% $Response->Include('INC/octo_main_menu.inc') %></td>
<td valign="top" align="center" width="*">
<AAT:Msg_Error />
