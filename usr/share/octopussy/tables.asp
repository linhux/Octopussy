<WebUI:PageTop title="_TABLES" help="tables" />
<%
my $f = $Request->Form();
my $table = $f->{table} || $Request->QueryString("table");
$table = (Octopussy::Table::Valid_Name($table) ? $table : undef);
my $action = $Request->QueryString("action");
my $sort = $Request->QueryString("tables_table_sort");
$table =~ s/ /_/g;

if (NULL($table))
{
	%><AAT:Inc file="octo_tables_list" url="./tables.asp" sort="$sort" /><%
}
else
{
	if ((!-f Octopussy::Table::Filename($table))
		&& ($Session->{AAT_ROLE} !~ /ro/i))
	{
		Octopussy::Table::New({ name => $table, description => $f->{description} });
		AAT::Syslog::Message("octo_WebUI", "GENERIC_CREATED", "Table", $table, $Session->{AAT_LOGIN});
		$Response->Redirect("./table_fields.asp?table=$table");
	}
	elsif (($action eq "remove") && ($Session->{AAT_ROLE} !~ /ro/i))
	{
		Octopussy::Table::Remove($table);
		AAT::Syslog::Message("octo_WebUI", "GENERIC_DELETED", "Table", $table, $Session->{AAT_LOGIN});
		$Response->Redirect("./tables.asp");
	}
	else
	{
		$Response->Redirect("./table_fields.asp?table=$table");
	}
}
%>
<WebUI:PageBottom />
