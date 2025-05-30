var secondaryTabs = {};

/**
 * Controls the Secondary Tab display
 */
secondaryTabs.SecondaryTabs = Class.create();
secondaryTabs.SecondaryTabs.prototype =
{
  initialize : function()
  {
    this.generalOffSetValue = 10;
    this.paneTabs = $("paneTabs");
    this.resize = false;

    if (this.paneTabs )
    {
      this._onWindowResize();
      Event.observe(window, 'resize', this._onWindowResize
          .bindAsEventListener(this));
      var overflowButton = $("overflowLiId");
      new page.FlyoutMenu( overflowButton );
    }
  },

  _onWindowResize : function(event)
  {
    if (this.resize)
    {
      return;
    }
    this.resize = true;
    var i,j, tab;
    var overflowMenu = $("overflowULId");
    var overflowButton = $("overflowLiId");
    overflowButton.className = "sub";
    overflowButton.show();
    var overflowButtonWidth = overflowButton.offsetWidth + this.generalOffSetValue;
    this.paneTabs.removeChild( overflowButton );
    // Resetting the List so the offsetWidth is set properly
    var overFlowLst = overflowMenu.getElementsByTagName('li');
    for ( j = 0; j < overFlowLst.length;)
    {
      tab = overFlowLst[j];
      this.paneTabs.appendChild(tab);
      tab.className = "";
    }

    var availableWidth = this.paneTabs.offsetWidth; // Getting the Width of the Tabs Div
    var orgTabList = this.paneTabs.getElementsByTagName('li'); // Getting the List of Tabs
    var overflowIndex = orgTabList.length;
    var hasOverFlow = false;

    // Get the Active Tab
    var activeTab = null;
    for ( j = 0; j < orgTabList.length; j++)
    {
      tab = orgTabList[j];
      if (tab.className.trim() == 'active')
      {
        activeTab = tab;
        break;
      }
    }
    var totalWidth = 0;
    var activeTabShown = false;
    var activeTabWidth = activeTab.offsetWidth + this.generalOffSetValue;
    // Calculating if we need to add tabs to overflow
    for ( i = 0; i < orgTabList.length; i++)
    {
      tab = orgTabList[i];
      var currentWidth = totalWidth + tab.offsetWidth + this.generalOffSetValue; // Calculating the current Tab width
      if ( !activeTabShown )
      {
        currentWidth += activeTabWidth; // if we include this tab, we must make sure there is enough room for left to display the active tab
      }
      if ( currentWidth > availableWidth )
      {
        if ( ( totalWidth + overflowButtonWidth ) > availableWidth )
        {
          // there is not enough room even for the drop down button so we back track one more tab, but still one tab should be visible
          overflowIndex = ( i>1?(i-1):1);
        }
        else
        {
          // we always show at least one element
          overflowIndex = i>1?i:1;
        }
        hasOverFlow = (orgTabList.length>1) ;
        break;
      }
      totalWidth += ( tab.offsetWidth + this.generalOffSetValue );
      if ( tab == activeTab )
      {
        activeTabShown = true;
      }
    }
    if (hasOverFlow)
    {
      this.menuOffsetDone = false;
      // Adding the tabs to the Overflow list - since we modify the container length changes on each iteration
      for ( i = overflowIndex; i < orgTabList.length; )
      {
        tab = orgTabList[i];
        if ( tab.className.trim() == 'active' )
        {
          // If the overflow list has the active tab, leave it to the tab list
          ++i;
          continue;
        }
        tab.className = "";
        overflowMenu.appendChild( tab );
      }
    } else
    {
      overflowButton.hide();
    }
    this.paneTabs.appendChild(overflowButton);
    this.resize = false;
  }
};
