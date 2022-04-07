using System;
using System.IO;
using System.Linq;
using System.Windows.Forms;

class test
{
	[STAThread]
	static void Main(string[] args)
	{
		Console.WriteLine( "移動フォルダ名を入力してください(なければ作成)" );
		string var_folder = Console.ReadLine();
		
		//カレントディレクトリ取得
		string var_path = Directory.GetCurrentDirectory();
		//作成フォルダのディレクトリパス作成
		string var_pathymd = Path.Combine(var_path , var_folder);
		//日付フォルダ作成
		DirectoryInfo var_di = Directory.CreateDirectory(var_folder);
		
		Console.WriteLine( "ファイル末尾に入れる文字を入力してください(不要ならEnter)" );
		string var_file = Console.ReadLine();
		
		/*
		//日付取得
		DateTime var_n = DateTime.Now;
		//日付名称変更
		string var_folder = var_n.ToString("yyyyMMdd");
		*/
		
		Console.WriteLine( "対象とする拡張子(xlsx、xlsm、jpg、csvなど)" );
		string var_ext1 = Console.ReadLine();
		//対象とする拡張子
		string var_ext = "*." + var_ext1;
		//カレントディレクトリ内のフォルダ名をすべて取得
		string[] var_files = Directory.GetFiles(var_path, var_ext);
		
		//カレントディレクトリ内のフォルダ名をすべて取得(パスなし)
		string[] var_nopath = Directory.GetFiles(var_path, var_ext).Select(x => Path.GetFileName(x)).ToArray();
		//配列を文字列に変換
		string clip = string.Join( "\n", var_nopath );
		//クリップボードにコピー
		Clipboard.SetDataObject( clip, true );
		
		Console.WriteLine( "ファイル確認中..." );
		foreach(string var in var_files)
		{
			//拡張子取得
			string var_Ext = Path.GetExtension(var);
			//拡張子なしのファイル名を取得
			string var_Del = Path.GetFileNameWithoutExtension(var);
			//新たなファイル名を作成/絶対Path作成
			var var_New = Path.Combine( var_pathymd , (var_Del + var_file + var_Ext) );
			//名前変更を実行
			File.Move( var, var_New );
			
			Console.WriteLine( var );
			Console.WriteLine( var_New );
		}
	}
}
