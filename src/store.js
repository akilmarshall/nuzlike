import { configureStore } from '@reduxjs/toolkit'
import playerReducer from './slice/Player'


export default configureStore({
    reducer: {
        player: playerReducer
    }
})
