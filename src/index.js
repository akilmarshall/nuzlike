import React from 'react'
import ReactDOM from 'react-dom/client'
import App from './App';
import ChooseStarter from './StarterSelect';
import Settings from './Settings';
import About from './About';
import Party from './Party';
import reportWebVitals from './reportWebVitals'
import { NextUIProvider } from '@nextui-org/react'
import { Provider } from 'react-redux'
import store from './store'
import { BrowserRouter, Routes, Route } from 'react-router-dom'

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <Provider store={store}>
        <NextUIProvider>
            <BrowserRouter>
                <Routes>
                    <Route path="/" element={<App />}/>
                    <Route path="choose-starter" element={<ChooseStarter />}/>
                    <Route path="settings" element={<Settings />}/>
                    <Route path="about" element={<About />}/>
                    <Route path="party" element={<Party />}/>
                </Routes>
            </BrowserRouter>
        </NextUIProvider>
    </Provider>
  </React.StrictMode>
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
