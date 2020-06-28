using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data;
using System.Data.SqlClient;

namespace SGBD_Lab1
{
	public partial class Form1 : Form
	{
		SqlConnection dbConn;
		SqlDataAdapter daItems, daLoot;
		DataSet ds;
		SqlCommandBuilder cb;
		BindingSource bsItems, bsLoot;

		private void btnAdd_Click(object sender, EventArgs e)
		{
			var sqlQuery = "SELECT * FROM Items";
			SqlDataAdapter dataAdapter = new SqlDataAdapter(sqlQuery, "Server = DESKTOP-040CNDA; Database = Minecraft; Trusted_Connection = True");
			DataSet dataSet = new DataSet();
			dataAdapter.Fill(dataSet, "Items");

			dataAdapter.TableMappings.Add("Iid", "Iid");
			dataAdapter.TableMappings.Add("Name", "Name");
			dataAdapter.TableMappings.Add("Type", "Type");
			dataAdapter.TableMappings.Add("Usage", "Usage");
			dataAdapter.TableMappings.Add("Durability", "Durability");
			dataAdapter.TableMappings.Add("Pid", "Pid");
			dataAdapter.TableMappings.Add("Bid", "Bid");
			dataAdapter.TableMappings.Add("Lid", "Lid");
			dataAdapter.TableMappings.Add("Tid", "Tid");

			var newRow = dataSet.Tables["Items"].NewRow();
			newRow["Iid"] = int.Parse(tbID.Text);
			newRow["Name"] = tbName.Text;
			newRow["Type"] = tbType.Text;
			newRow["Usage"] = tbUsage.Text;
			newRow["Durability"] = int.Parse(tbDurability.Text);
			newRow["Pid"] = int.Parse(tbPlayer.Text);
			newRow["Bid"] = int.Parse(tbBiom.Text);
			newRow["Lid"] = int.Parse(tbLoot.Text);
			//newRow["Tid"] = int.Parse(tbType.Text);

			dataSet.Tables["Items"].Rows.Add(newRow);

			new SqlCommandBuilder(dataAdapter);
			dataAdapter.Update(dataSet, "Items");

			this.Form1_Load(sender, e);

		}

		private void btnRemove_Click(object sender, EventArgs e)
		{
			var sqlQuery = "SELECT * FROM Items";
			SqlConnection connection = new SqlConnection(@"Data Source = DESKTOP-040CNDA; Initial Catalog =
Minecraft; Integrated Security = true");
			SqlDataAdapter dataAdapter = new SqlDataAdapter(sqlQuery, connection);
			DataSet dataSet = new DataSet();
			dataAdapter.Fill(dataSet, "Items");
			//luam o data cu fill si local modificari
			//
			string removeCommand = "DELETE FROM Items WHERE Iid = " + tbID.Text;

			SqlDataAdapter updateItems = new SqlDataAdapter();

			try
			{
				connection.Open();
				SqlCommand cmd = new SqlCommand(removeCommand, connection);
				updateItems.DeleteCommand = cmd;
				updateItems.DeleteCommand.ExecuteNonQuery();

				this.Form1_Load(sender, e);

			}
			catch (Exception ex)
			{
				connection.Close();
			}


		}

		private void btnUpdateDB_Click(object sender, EventArgs e)
		{
			var sqlQuery = "SELECT * FROM Items";
			SqlDataAdapter dataAdapter = new SqlDataAdapter(sqlQuery, "Server = DESKTOP-040CNDA; Database = Minecraft; Trusted_Connection = True");
			DataSet dataSet = new DataSet();
			dataAdapter.Fill(dataSet, "Items");

			//string updateCommand = "UPDATE Items SET Name = " + tbName.Text + ", Type = " + tbType.Text + ", Usage = " + tbUsage.Text + " where Iid = " + tbID.Text;
			SqlConnection connection = new SqlConnection(@"Data Source = DESKTOP-040CNDA; Initial Catalog =
Minecraft; Integrated Security = true");
			/*SqlDataAdapter updateItems = new SqlDataAdapter();*/ ddhe_

			DataTable dt = dataSet.Tables["Items"];
			dt.Rows[dgvItems.CurrentRow.Index]["Name"] = tbName.Text;
			dt.Rows[dgvItems.CurrentRow.Index]["Type"] = tbType.Text;
			dt.Rows[dgvItems.CurrentRow.Index]["Usage"] = tbUsage.Text;
			dt.Rows[dgvItems.CurrentRow.Index]["Durability"] = int.Parse(tbDurability.Text);
			dt.Rows[dgvItems.CurrentRow.Index]["Pid"] = int.Parse(tbPlayer.Text);
			dt.Rows[dgvItems.CurrentRow.Index]["Bid"] = int.Parse(tbBiom.Text);
			dt.Rows[dgvItems.CurrentRow.Index]["Lid"] = int.Parse(tbLoot.Text);
			/*SqlCommand cmd = new SqlCommand();
			SqlDataAdapter updateItems = new SqlDataAdapter();
			connection.Open();
			cmd.CommandText = "UPDATE Items SET Name = " + tbName.Text + ", Type = " + tbType.Text + ", Usage = " + tbUsage.Text + " where Iid = " + tbID.Text;
			updateItems.UpdateCommand = cmd;
			updateItems.UpdateCommand.ExecuteNonQuery();
			connection.Close();*/


			new SqlCommandBuilder(dataAdapter);
			dataAdapter.Update(dataSet, "Items");

			this.Form1_Load(sender, e);


		}

		public Form1()
		{
			InitializeComponent();
			
		}

		private void Form1_Load(object sender, EventArgs e)
		{
			

			dbConn = new SqlConnection(@"Data Source = DESKTOP-040CNDA; Initial Catalog =
Minecraft; Integrated Security = true");
			ds = new DataSet();
			daItems = new SqlDataAdapter("SELECT * FROM Items", dbConn);
			daLoot = new SqlDataAdapter("SELECT * FROM Loot", dbConn);
			cb = new SqlCommandBuilder(daItems);
			daItems.Fill(ds, "Items");
			daLoot.Fill(ds, "Loot");
			DataRelation dr = new DataRelation("FK_Items_Loot",
				ds.Tables["Loot"].Columns["Lid"],
				ds.Tables["Items"].Columns["Lid"]);
			ds.Relations.Add(dr);

			bsLoot = new BindingSource();
			bsLoot.DataSource = ds;
			bsLoot.DataMember = "Loot";
			bsItems = new BindingSource();
			bsItems.DataSource = bsLoot;
			bsItems.DataMember = "FK_Items_Loot";
			dgvLoot.DataSource = bsLoot;
			dgvItems.DataSource = bsItems;


		}
	}
}
