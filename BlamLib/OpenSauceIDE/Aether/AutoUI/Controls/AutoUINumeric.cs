﻿using System;
using System.Windows.Forms;
using System.Globalization;

namespace OpenSauceIDE.Aether.AutoUI.Controls
{
	///-------------------------------------------------------------------------------------------------
	/// <summary>	An automatic user interface numeric text box. </summary>
	///-------------------------------------------------------------------------------------------------
	[Attributes.AutoUISize(70, 0, 70, 0)]
	public abstract class AutoUINumeric<T> : TextBox, IAutoUIControl
	{
		#region IAutoUIControl Members
		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets or sets information describing the target member. </summary>
		/// <value>	Information describing the target member. </value>
		///-------------------------------------------------------------------------------------------------
		public IAutoUIMemberInfo MemberInfo { get; private set; }

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Sets the target member info for the control. </summary>
		/// <param name="memberInfo">	Information describing the target member. </param>
		///-------------------------------------------------------------------------------------------------
		public void SetMemberInfo(IAutoUIMemberInfo memberInfo)
		{
			MemberInfo = memberInfo;
		}

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Sets the source object to bind the control to. </summary>
		/// <param name="sourceObject">	The source object to bind to. </param>
		///-------------------------------------------------------------------------------------------------
		public void SetSource(object sourceObject)
		{
			// Bind the controls Text field to the source objects member
			Binding dataBinding = new Binding("Text"
				, sourceObject
				, MemberInfo.Name
				, true
				, DataSourceUpdateMode.OnPropertyChanged
				, default(T));

			DataBindings.Add(dataBinding);
		}
		#endregion IAutoUIControl Members
	}
}