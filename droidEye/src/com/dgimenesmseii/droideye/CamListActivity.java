package com.dgimenesmseii.droideye;

import vstc2.nativecaller.ContentCommon;
import vstc2.nativecaller.NativeCaller;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.v4.app.Fragment;
import android.support.v7.app.ActionBarActivity;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.Button;

import com.dgimenesmseii.droideye.BridgeService.AddCameraInterface;
import com.dgimenesmseii.droideye.BridgeService.IpcamClientInterface;

public class CamListActivity extends ActionBarActivity implements IpcamClientInterface, AddCameraInterface {
	private Intent intentbrod = null;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_cam_list);
		if (savedInstanceState == null) {
			PlaceholderFragment placeholderFragment = new PlaceholderFragment();
			placeholderFragment.setActivity(this);
			getSupportFragmentManager().beginTransaction().add(R.id.container, placeholderFragment).commit();
		}
		intentbrod = new Intent("drop");
		connectWithCAM();
	}

	private void connectWithCAM() {
		Intent intent = new Intent();
		intent.setClass(CamListActivity.this, BridgeService.class);
		startService(intent);
		new Thread(new Runnable() {
			@Override
			public void run() {
				NativeCaller.PPPPInitial("ABC");
				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				BridgeService.setAddCameraInterface(CamListActivity.this);
			}
		}).start();
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.cam_list, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}

	private Handler hPPPPMsgHandler = new Handler() {
		public void handleMessage(Message msg) {
			System.out.println("@@@@@@@@@@@@@@@@@@@@@@@@ AQUI @@@@@@@@@@@@@@@");
			Bundle bd = msg.getData();
			int msgParam = bd.getInt("msgparam");
			System.out.println("STATUS: " + msgParam);
			int msgType = msg.what;
			Log.i("aaa", "====" + msgType + "--msgParam:" + msgParam);
			String did = bd.getString("did");
			switch (msgType) {
			case ContentCommon.PPPP_MSG_TYPE_PPPP_STATUS:
				// int resid;
				// switch (msgParam) {
				// case ContentCommon.PPPP_STATUS_CONNECTING:// 0
				// resid = R.string.pppp_status_connecting;
				// progressBar.setVisibility(View.VISIBLE);
				// tag = 2;
				// break;
				// case ContentCommon.PPPP_STATUS_CONNECT_FAILED:// 3
				// resid = R.string.pppp_status_connect_failed;
				// progressBar.setVisibility(View.GONE);
				// tag = 0;
				// break;
				// case ContentCommon.PPPP_STATUS_DISCONNECT:// 4
				// resid = R.string.pppp_status_disconnect;
				// progressBar.setVisibility(View.GONE);
				// tag = 0;
				// break;
				// case ContentCommon.PPPP_STATUS_INITIALING:// 1
				// resid = R.string.pppp_status_initialing;
				// progressBar.setVisibility(View.VISIBLE);
				// tag = 2;
				// break;
				// case ContentCommon.PPPP_STATUS_INVALID_ID:// 5
				// resid = R.string.pppp_status_invalid_id;
				// progressBar.setVisibility(View.GONE);
				// tag = 0;
				// break;
				// case ContentCommon.PPPP_STATUS_ON_LINE:// 2
				// resid = R.string.pppp_status_online;
				// progressBar.setVisibility(View.GONE);
				// tag = 1;
				// break;
				// case ContentCommon.PPPP_STATUS_DEVICE_NOT_ON_LINE:// 6
				// resid = R.string.device_not_on_line;
				// progressBar.setVisibility(View.GONE);
				// tag = 0;
				// break;
				// case ContentCommon.PPPP_STATUS_CONNECT_TIMEOUT:// 7
				// resid = R.string.pppp_status_connect_timeout;
				// progressBar.setVisibility(View.GONE);
				// tag = 0;
				// break;
				// case ContentCommon.PPPP_STATUS_CONNECT_ERRER:// 8
				// resid = R.string.pppp_status_pwd_error;
				// progressBar.setVisibility(View.GONE);
				// tag = 0;
				// break;
				// default:
				// resid = R.string.pppp_status_unknown;
				// }
				// textView_top_show.setText(getResources().getString(resid));
				if (msgParam == ContentCommon.PPPP_STATUS_ON_LINE) {
					NativeCaller.PPPPGetSystemParams(did, ContentCommon.MSG_TYPE_GET_PARAMS);
				}
				if (msgParam == ContentCommon.PPPP_STATUS_INVALID_ID || msgParam == ContentCommon.PPPP_STATUS_CONNECT_FAILED
						|| msgParam == ContentCommon.PPPP_STATUS_DEVICE_NOT_ON_LINE || msgParam == ContentCommon.PPPP_STATUS_CONNECT_TIMEOUT
						|| msgParam == ContentCommon.PPPP_STATUS_CONNECT_ERRER) {
					NativeCaller.StopPPPP(did);
				}
				break;
			case ContentCommon.PPPP_MSG_TYPE_PPPP_MODE:
				break;
			}
		}
	};

	@Override
	public void callBackUserParams(String did, String user1, String pwd1, String user2, String pwd2, String user3, String pwd3) {
		// TODO Auto-generated method stub

	}

	@Override
	public void CameraStatus(String did, int status) {
		// TODO Auto-generated method stub

	}

	@Override
	public void BSSnapshotNotify(String did, byte[] bImage, int len) {
		// TODO Auto-generated method stub

	}

	@Override
	public void BSMsgNotifyData(String did, int type, int param) {
		Log.d("ip", "type:" + type + " param:" + param);
		Bundle bd = new Bundle();
		Message msg = hPPPPMsgHandler.obtainMessage();
		msg.what = type;
		bd.putInt("msgparam", param);
		bd.putString("did", did);
		msg.setData(bd);
		hPPPPMsgHandler.sendMessage(msg);
		if (type == ContentCommon.PPPP_MSG_TYPE_PPPP_STATUS) {
			 intentbrod.putExtra("ifdrop", param);
			 sendBroadcast(intentbrod);
		}
	}

	/**
	 * A placeholder fragment containing a simple view.
	 */
	public static class PlaceholderFragment extends Fragment {

		private static final String CAM_ID = "VSTC125645YKRSE";
		private Button button;
		private CamListActivity activity;

		public PlaceholderFragment() {
		}

		public void setActivity(CamListActivity activity) {
			this.activity = activity;
		}

		@Override
		public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
			View rootView = inflater.inflate(R.layout.fragment_cam_list, container, false);
			button = (Button) rootView.findViewById(R.id.button1);
			button.setOnClickListener(new OnClickListener() {
				@Override
				public void onClick(View v) {
					BridgeService.setIpcamClientInterface(PlaceholderFragment.this.activity);
					NativeCaller.Init();
					new Thread(new Runnable() {
						@Override
						public void run() {
							try {
								Thread.sleep(500);
							} catch (InterruptedException e) {
								e.printStackTrace();
							}
							int r = NativeCaller.StartPPPP(CAM_ID, "admin", "888888");
							System.out.println(String.valueOf(r));
							try {
								Thread.sleep(500);
							} catch (InterruptedException e) {
								e.printStackTrace();
							}
							NativeCaller.PPPPGetSystemParams(CAM_ID,
									ContentCommon.MSG_TYPE_GET_CAMERA_PARAMS);
//							for (int i = 0; i < 10; i++) {
//								NativeCaller.PPPPPTZControl(CAM_ID, ContentCommon.CMD_PTZ_RIGHT);
//								try {
//									Thread.sleep(200);
//								} catch (InterruptedException e) {
//									e.printStackTrace();
//								}
//							}
						}
					}).start();
				}
			});
			return rootView;
		}
	}

	@Override
	public void callBackSearchResultData(int cameraType, String strMac, String strName, String strDeviceID, String strIpAddr, int port) {
		// TODO Auto-generated method stub
		
	}

}
